#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

static int max_line = 1000;

class Iworker {
    public:
        virtual std::vector<std::string> execute(std::vector<std::string> &text) = 0;
};

class Readfile: public Iworker {
    public:
        std::string file_name;
        
        Readfile(char* filename);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Writefile: public Iworker {
    public:
        std::string file_name;
        
        Writefile(char* filename);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Grep: public Iworker {
    public:
        std::string word;

        Grep(char* word_to_grep);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

