#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <exception>
#include "trit.h"

static const std::string help =
"Usage: \n hasher -m <hash_type> <filename> or \n\
<filename> -m <hash_type> \n\n\
-h, --help      output usage information and exit \n\n\
hash_type: crc32, sum32 \n";


int main() {

    std::cout << "Privet!" << std::endl;

    return 0;
}


/*void print_result(uint32_t result)
{
    std::cout << std::hex <<"0x"<< result << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string hash_type_;
        std::string path_;
        if (!strcmp(argv[1], "-m"))
        {
            hash_type_ = argv[2];
            path_ = argv[3];
        }
        else if (!strcmp(argv[2], "-m"))
        {
            path_ = argv[1];
            hash_type_ = argv[3];
        }

        try
        {
            if (hash_type_ == "crc32")
            {
                print_result(CRC32_count(path_));
                return 0;
            }

            if (hash_type_ == "sum32")
            {
                print_result(SUM32_count(path_));
                return 0;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }

    if (argc == 2)
    {
        if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        {
            std::cout << help << std::endl;
            return 0;
        }
    }

    std::cerr << help << std::endl;
    return 1;
}*/
