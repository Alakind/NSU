#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <exception>
#include "executor.h"


int main(int argc, char* argv[]) {

    if (argc > 1) {
        std::string filename(argv[1]);
        workflow_execute(filename);
    }

    return 0;
}
