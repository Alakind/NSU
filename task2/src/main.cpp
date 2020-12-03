#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <exception>
#include "executor.h"


int main(int argc, char* argv[]) {

    if (argc > 1) {
        workflow_execute(argv[1]);
    }

    return 0;
}
