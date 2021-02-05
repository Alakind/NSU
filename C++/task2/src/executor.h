#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <exception>

static int max_line = 1000;

class Iworker {
    public:
        virtual std::vector<std::string> execute(std::vector<std::string> &text) = 0;
};

class WorkflowException: std::exception {
    public:
        std::string error;
        WorkflowException(std::string &err_massage);
        const char* what();
};

class Readfile: public Iworker {
    public:
        std::string file_name;
        
        explicit Readfile(std::string filename);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Writefile: public Iworker {
    public:
        std::string file_name;
        
        explicit Writefile(std::string filename);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Grep: public Iworker {
    public:
        std::string word;

        explicit Grep(std::string word_to_grep);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Sort: public Iworker {
    public:
        explicit Sort();

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Replace: public Iworker {
    public:
        std::string word_from;
        std::string word_to;

        explicit Replace(std::string word_fr, std::string word_t);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

class Dump: public Iworker {
    public:
        std::string file_name;

        explicit Dump(std::string filename);

        virtual std::vector<std::string> execute(std::vector<std::string> &text);
};

std::vector<int> get_sequence(std::string string);

void do_command(std::string line, std::vector<std::string>& text);

void workflow_execute(std::string filename);

class Validator {
    public:
        void is_valid(std::string filename);
};
