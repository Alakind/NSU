#include <iostream>
//#include <winsock2.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/poll.h>
#include <netdb.h>
#include <string>
#include <sys/types.h>
#include <vector>
#include <algorithm>

#include "functions.h"

int main4(int argc, char** argv) {
    srand(time(NULL));

    if (argc < 2) {
        std::cout << "Input ip adress as argument" << std::endl;
        return 0;
    }

    std::string my_name = std::to_string(rand());
    std::cout << "I'm " << my_name << std::endl;

    int optval = 1;

    // INPUT
    int in_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (in_socket < 0) {
        std::cout << "Error making an in socket" << std::endl;
        return 0;
    }
    if (setsockopt(in_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval) < 0) {
        std::cout << "Error reuse addr" << std::endl;
        return 0;
    }
    if (setsockopt(in_socket, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof optval) < 0) {
        std::cout << "Error reuse port" << std::endl;
        return 0;
    }

    struct sockaddr_in mcast_group;
    mcast_group.sin_family = AF_INET;
    mcast_group.sin_port = htons(PORT);
    mcast_group.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(in_socket, (const struct sockaddr*) &mcast_group, sizeof(mcast_group)) < 0) {
        std::cout << "Error bind" << std::endl;
        return 0;
    }

    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr(argv[1]);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(in_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
        std::cout << "Error adding to membership" << std::endl;
        return 0;
    }

    // OUTPUT
    int out_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (out_socket < 0) {
        std::cout << "Error making an out socket" << std::endl;
    }

    struct pollfd sock_desc {
        .fd = in_socket,
        .events = POLLIN
    };

    describe_proccess(my_name, out_socket, reinterpret_cast<sockaddr *>(&mcast_group), sizeof(mcast_group));


    while (true) {
        int poll_res = poll(&sock_desc, 1, 100);

        if (poll_res < 0) {
            std::cout << "Error polin" << std::endl;
            return 0;
        }

        if (poll_res != 0) {

            if (sock_desc.revents != POLLIN) {
                std::cout << "no polin" << std::endl;
            }

            char buffer[MAXLEN];
            struct sockaddr_in client_adress;
            int client_adress_size = sizeof(client_adress);

            ssize_t readed = recvfrom(in_socket,
                (char*) buffer,
                MAXLEN,
                MSG_WAITALL,
                (struct sockaddr *) &client_adress,
                (socklen_t*) &client_adress_size);
            
            if (readed < 0) {
                std::cout << "Error reading" << std::endl;
                return 0;
            }

            buffer[readed] = '\0';

            std::string gotten_name = buffer;

            if (my_name == gotten_name) {
                continue;
            }

            char host[NI_MAXHOST];
            std::string ip;
            if (getnameinfo((sockaddr*) &client_adress,
                client_adress_size,
                host,
                NI_MAXHOST,
                nullptr,
                0,
                NI_NUMERICHOST) != 0)
            {
                std::cout << "Error getnameinfo" << std::endl;
                return 0;
            } else {
                ip = std::string(host);
            }

            copies = update_copies(copies, gotten_name);
        } else {
            describe_proccess(my_name,
                out_socket,
                reinterpret_cast<sockaddr *>(&mcast_group),
                sizeof(mcast_group)
            );
            copies = update_copies(copies);
        }

        print_copies(copies);
        //std::cout << "Iter" << std::endl;
    }

    std::cout << "Finished successfully?????" << std::endl;
    return 0;
}
