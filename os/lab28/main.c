#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Pass URL as only argument\n");
        return 0;
    }

    char* url = argv[1];

    printf("URL: %s\n", url);

    return 0;
}
