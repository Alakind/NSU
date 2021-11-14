#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <poll.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>

#define MAX_SIZE 1000
#define MAX_URL_SIZE 256
#define POLL_TIMEOUT 10000
#define LINES_PER_SCREEN 26
#define BUF_SIZE 2048
#define PORT 80
#define BODY_DELIM "\r\n\r\n"

struct termios backup;
int tios_saved = 0;
int tty = STDIN_FILENO;

void restore_term() {
    if (tcsetattr(tty, TCSANOW, &backup) == -1) {
        perror("lab36 error:: tcsetattr() failed:");
    }
}

void sigint_handle() {
    restore_term();
    exit(1);
}

int get_http(char* full_url) {
    char host[MAX_URL_SIZE];
    char url[MAX_URL_SIZE];

    int idx;
    for (idx = 0; full_url[idx] != '\0'; idx++) {
        if (idx > MAX_URL_SIZE) {
            return -1;
        }

        if (full_url[idx] == '/') {
            break;
        }
    }

    if (full_url[idx] == '\0') {
        strcpy(host, full_url);
        strcpy(url, "");
    } else {
        strcpy(url, full_url + idx);
        full_url[idx] = '\0';
        strcpy(host, full_url);
    }

    printf("Trying to connect to %s...\n", host);
    printf("Getting %s...\n", url);

    char message[MAX_SIZE];
    char response[BUF_SIZE];

    char *get_header = "GET %s HTTP/1.0\r\n\r\n";
    snprintf(message, MAX_SIZE, get_header, url);

    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("lab36 error:: socket() failed:");
        return -1;
    }

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        perror("lab36 error:: gethostbyname() failed:");
        close(socket_desc);
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("lab36 error:: connect() failed:");
        close(socket_desc);
        return -1;
    }
    printf("Connected successfully!\n");

    int w = write(socket_desc, message, strlen(message));
    if (w == -1) {
        perror("write");
        close(socket_desc);
        return -1;
    }

    struct pollfd fds[2];
    fds[0].fd = socket_desc;
    fds[0].events = POLLIN | POLLHUP;
    fds[0].revents = 0;

    fds[1].fd = tty;
    fds[1].events = POLLIN;
    fds[1].revents = 0;

    fcntl(socket_desc, F_SETFL, O_NONBLOCK);

    int lines_written = 0;
    int bytes_read = 0;
    int bytes_written = 0;
    int head_skipped = 0;

    while (1) {
        fds[0].revents = 0;
        fds[1].revents = 0;

        int pollres = poll(fds, 2, POLL_TIMEOUT);
        if (pollres == 0) {
            continue;
        } else if (pollres == -1) {
            perror("lab36 error:: poll() failed:");
            return -1;
        }

        if ((fds[0].revents & POLLHUP) != 0) {
            printf("POLLHUP\n");
            fds[0].events = 0;
        }

        if ((fds[0].revents & POLLIN) != 0) {
            ssize_t r = read(socket_desc, response + bytes_read, BUF_SIZE - bytes_read);
            if (r == 0) {
                fds[0].events = 0;
            } else if (r == -1) {
                perror("lab36 error:: read() failed:");
                return -1;
            }

            bytes_read += r;
        }

        if ((fds[1].revents & POLLIN) != 0) {
            char c;
            read(tty, &c, 1);
            if (c == ' ') {
                lines_written = 0;
                fds[1].revents = 0;
            }
            if (c == 'q') {
                printf("Exiting...\n");
                return 0;
            }
        }

        if (lines_written <= LINES_PER_SCREEN) {
            if (!head_skipped) {
                char* pos = strstr(response, BODY_DELIM);
                if (pos != NULL) {
                    bytes_written = pos - response + strlen(BODY_DELIM);
                    head_skipped = 1;
                }
            }
            if (head_skipped) {
                int tpos;
                for (tpos = bytes_written; tpos < bytes_read; tpos++) {
                    if (response[tpos] == '\n' || response[tpos] == '\r') {
                        lines_written++;
                        putchar('\n');
                    } else {
                        putchar(response[tpos]);
                    }
                    if (lines_written > LINES_PER_SCREEN) {
                        printf("Press space to scroll down...\n");
                        tpos++;
                        break;
                    }
                }
                bytes_written = tpos;
            }
        }

        if (bytes_read == bytes_written && fds[0].events == 0) {
            break;
        }
    }

    close(socket_desc);

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("lab36 error:: need URL address!\n");
        return 1;
    }

    struct termios tp;
    if (tcgetattr(tty, &tp) == -1) {
        perror("lab36 error:: tcgetattr() failed:");
    }

    backup = tp;
    tp.c_lflag &= ~ECHO;
    tp.c_lflag &= ~ICANON;
    tp.c_cc[VMIN] = 1;

    if (tcsetattr(tty, TCSAFLUSH, &tp) == -1) {
        perror("lab36 error:: tcsetattr() failed:");
    }

    struct sigaction sa;
    sa.sa_handler = sigint_handle;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    get_http(argv[1]);

    putchar('\n');
    restore_term();

    return 0;
}