#include <iostream>
#include <cstring>
#include "ipv4.cpp"
#include "ipv6.cpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Input ip adress as argument" << std::endl;
        return 0;
    }

    for (unsigned int i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] == ':') {
            main6(argc, argv);
            return 0;
        }
    }

    main4(argc, argv);

    return 0;
}
