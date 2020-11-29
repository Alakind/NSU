#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

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

class Sort: public Iworker {
    public:
        Sort();

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Replace: public Iworker {
    public:
        std::string word_from;
        std::string word_to;

        Replace(char* word_fr, char* word_t);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Dump: public Iworker {
    public:
        std::string file_name;
        
        Dump(char* filename);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};
