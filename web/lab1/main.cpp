#include <iostream>
//#include <winsock2.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Input ip adress as argument" << std::endl;
        return 0;
    }

    int true_flag = 1;

    // INPUT
    int in_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (in_socket < 0) {
        std::cout << "Error making an in socket" << std::endl;
        return 0;
    }
    if (setsockopt(in_socket, SOL_SOCKET, SO_REUSEADDR, &true_flag, sizeof true_flag) < 0) {
        std::cout << "Error reuse addr" << std::endl;
        return 0;
    }
    if (setsockopt(in_socket, SOL_SOCKET, SO_REUSEPORT, &true_flag, sizeof true_flag) < 0) {
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

    std::cout << "Finished successfully!" << std::endl;

    return 0;
}
