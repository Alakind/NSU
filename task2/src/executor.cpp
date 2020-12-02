#include "executor.h"

Readfile::Readfile(char* filename) {
    std::string filename_str = filename;
    file_name = filename_str;
}

std::vector<std::string> Readfile::execute(std::vector<std::string> &text) {
    //std::cout << "CHEBOKSARI!" << std::endl;

    std::ifstream fin;
    fin.open(this->file_name);


    std::string tmp_string;
    while(!fin.eof() && getline(fin, tmp_string, '\n')) {
        //std::cout << "CHEBOKSARI!" << std::endl;
        //getline(fin, tmp_string, '\n');
        text.push_back(tmp_string);
    }

    fin.close();

    return text;
}

Writefile::Writefile(char* filename) {
    std::string filename_str = filename;
    file_name = filename_str;
}

std::vector<std::string> Writefile::execute(std::vector<std::string> &text) {
    std::ofstream fout;
    fout.open(this->file_name);

    std::string tmp_string;
    for (int i = 0; i < text.size(); i++) {
        fout << text.at(i) << std::endl;
    }

    fout.close();

    return text;
}

Grep::Grep(char* word_to_grep) {
    std::string word_str = word_to_grep;
    word = word_str;
}

std::vector<std::string> Grep::execute(std::vector<std::string> &text) {

    for(int i = 0; i < text.size(); i++) {
        if (text.at(i).find(word) == std::string::npos) {
            text.erase(text.begin() + i);
            i--;
        }
    }

    return text;
}

Sort::Sort() {};

std::vector<std::string> Sort::execute(std::vector<std::string> &text) {
    std::sort(text.begin(), text.end());

    return text;
}

Replace::Replace(char* word_fr, char* word_t) {
    std::string word_from_str = word_fr;
    std::string word_to_str = word_t;
    word_from = word_from_str;
    word_to = word_to_str;
}

std::vector<std::string> Replace::execute(std::vector<std::string> &text) {
    for(int i = 0; i < text.size(); i++) {
        size_t start =  text.at(i).find(word_from);
        if (start != std::string::npos) {
            text.at(i).replace(start, word_from.size(), word_to);
        }
    }

    return text;
}

Dump::Dump(char* filename) {
    std::string filename_str = filename;
    file_name = filename_str;
}

std::vector<std::string> Dump::execute(std::vector<std::string> &text) {

    std::ofstream fout;
    fout.open(this->file_name);

    std::string tmp_string;
    for (int i = 0; i < text.size(); i++) {
        fout << text.at(i) << std::endl;
    }

    fout.close();

    return text;
}

std::pair<int, std::string> get_block(std::string string) {

    int i = 0;
    while (string.at(i) != ' ') {
        i++;
    }

    std::string str_number = string.substr(0, i);
    int number = stoi(str_number);

    i++;
    while (string.at(i) != ' ') {
        i++;
    }
    i++;

    //std::cout << string << std::endl;
    int start = i;
    while (string.at(i) != '\n' && string.at(i) != '\r') {
        i++;
    }

    std::string command = string.substr(start, i - start);

    std::pair<int, std::string> result (number, command);
    return result;
}

std::vector<int> get_sequence(std::string string) {
    int i = 0;
    std::vector<int> sequence;

    int start = i;
    do {
        if (string.at(i) == ' '  && string.at(i - 1) != '>') {
            std::string str_tmp = string.substr(start, i - start);
            int number = stoi(str_tmp);
            sequence.push_back(number);
        }
        if (string.at(i) == '>') {
            start = i + 2;
        }
        i++;
    } while (i < string.size());

    std::string str_tmp = string.substr(start, i - start);
    int number = stoi(str_tmp);
    sequence.push_back(number);

    return sequence;
}

void do_command(std::string line, std::vector<std::string>& text) {
    // seeking for command
    int i = 0;
    while(line.at(i) != ' ' && line.at(i) != '\n' && line.at(i) != '\r') {
        i++;
    }
    std::string command = line.substr(0, i);
    
    //std::cout << line << std::endl;
    //std::cout << i << std::endl;

    // seeking for first argument
    int start = i + 1;
    std::string first_argument_str;
    char* first_argument;
    if (line.at(i) != '\n' && line.at(i) != '\r') {
        i++;
        while(i < line.size() && line.at(i) != ' ' && line.at(i) != '\n' && line.at(i) != '\r') {
            i++;
        }
        first_argument_str = line.substr(start, i - start);
    
        first_argument = (char*) first_argument_str.c_str();
    }

    // seeking for second argument
    start = i + 1;
    std::string second_argument_str;
    char* second_argument;
    if (i < line.size() && line.at(i) != '\n' && line.at(i) != '\r') {
        i++;
        while(i < line.size() && line.at(i) != ' ' && line.at(i) != '\n' && line.at(i) != '\r') {
            i++;
        }
        second_argument_str = line.substr(start, i - start);

        second_argument = (char*) second_argument_str.c_str();
    }

    std::cout << command << std::endl;
    std::cout << first_argument << std::endl;
    std::cout << second_argument << std::endl << std::endl;

    // calculating
    if (command.compare("readfile")) {
        Readfile doer(first_argument);
        doer.execute(text);
    } else if(command.compare("writefile")) {
        Writefile doer(first_argument);
        doer.execute(text);
    } else if(command.compare("grep")) {
        Grep doer(first_argument);
        doer.execute(text);
    } else if(command.compare("sort") || command.compare("sort\n") || command.compare("sort\r")) {
        Sort doer;
        doer.execute(text);
    } else if(command.compare("replace") || command.compare("replace\n") || command.compare("replace\r")) {
        Replace doer(first_argument, second_argument);
        doer.execute(text);
    } else if(command.compare("dump")) {
        Dump doer(first_argument);
        doer.execute(text);
    }

}

void workflow_execute(char* filename) {
    // opening file
    std::ifstream fin;
    fin.open(filename);

    std::string tmp_string;

    // skipping desc
    getline(fin, tmp_string, '\n');
    getline(fin, tmp_string, '\n');

    std::map<int, std::string> commands_map;

    // reading commands
    while (tmp_string.compare("csed\n") && tmp_string.compare("csed\r")) {
        //std::cout << tmp_string << std::endl;
        std::pair<int, std::string> to_map = get_block(tmp_string);

        commands_map.insert(to_map);

        getline(fin, tmp_string, '\n');
    }

    // reading sequence
    getline(fin, tmp_string, '\n');
    std::vector<int> sequence = get_sequence(tmp_string);

    // calculating
    std::vector<std::string> text;
    for (int i = 0; i < sequence.size(); i++) {
        std::cout << "AIAIAIAIAIAAIAIAI" << std::endl;
        do_command(commands_map[sequence.at(i)], text);
    }
    std::cout << "Vse tyt zashibis!" << std::endl;
}
