#include "executor.h"

Readfile::Readfile(std::string filename) {
    //std::string filename_str = filename;
    file_name = filename;
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

Writefile::Writefile(std::string filename) {
    //std::string filename_str = filename;
    file_name = filename;
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

Grep::Grep(std::string word_to_grep) {
    //std::string word_str = word_to_grep;
    word = word_to_grep;
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

Replace::Replace(std::string word_fr, std::string word_t) {
    //std::string word_from_str = word_fr;
    //std::string word_to_str = word_t;
    word_from = word_fr;
    word_to = word_t;
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

Dump::Dump(std::string filename) {
    //std::string filename_str = filename;
    file_name = filename;
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
    //std::cout << "started doing the command" << std::endl;
    // seeking for command
    int i = 0;
    while(line.at(i) != ' ' && line.at(i) != '\n' && line.at(i) != '\r') {
        i++;
        if (i >= line.size()) {
            break;
        }
    }
    std::string command = line.substr(0, i);
    
    //std::cout << line << std::endl;
    //std::cout << i << std::endl;

    // seeking for first argument
    int start = i + 1;
    std::string first_argument_str;
    char* first_argument = (char*) "";
    if (i < line.size() && line.at(i) != '\n' && line.at(i) != '\r') {
        i++;
        while(line.at(i) != ' ' && line.at(i) != '\n' && line.at(i) != '\r') {
            i++;
            if (i >= line.size()) {
                break;
            }
        }
        first_argument_str = line.substr(start, i - start);
    
        first_argument = (char*) first_argument_str.c_str();
    }

    // seeking for second argument
    start = i + 1;
    std::string second_argument_str;
    char* second_argument = (char*) "";
    if (i < line.size() && line.at(i) != '\n' && line.at(i) != '\r') {
        i++;
        while(line.at(i) != ' ' && line.at(i) != '\n' && line.at(i) != '\r') {
            i++;
            if (i >= line.size()) {
                break;
            }
        }
        second_argument_str = line.substr(start, i - start);

        second_argument = (char*) second_argument_str.c_str();
    }

    //std::cout << command << std::endl;
    //std::cout << first_argument << std::endl;
    //std::cout << second_argument << std::endl << std::endl;

    // calculating
    if (!command.compare("readfile")) {
        Readfile doer(first_argument);
        doer.execute(text);
    } else if(!command.compare("writefile")) {
        Writefile doer(first_argument);
        doer.execute(text);
    } else if(!command.compare("grep")) {
        Grep doer(first_argument);
        doer.execute(text);
    } else if(!command.compare("sort") || !command.compare("sort\n") || !command.compare("sort\r")) {
        Sort doer;
        doer.execute(text);
    } else if(!command.compare("replace") || !command.compare("replace\n") || !command.compare("replace\r")) {
        Replace doer(first_argument, second_argument);
        doer.execute(text);
    } else if(!command.compare("dump")) {
        Dump doer(first_argument);
        doer.execute(text);
    }

}

void workflow_execute(std::string filename) {
    // Checking if file is valid
    Validator validator;
    try {
        validator.is_valid(filename);
    }
    catch(WorkflowException &error) {
        std::cerr << error.what() << std::endl;
        return;
    }

    // opening file
    std::ifstream fin;
    fin.open(filename.c_str());

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
        do_command(commands_map[sequence.at(i)], text);
    }

    return;
}

void Validator::is_valid(std::string filename) {
    // opening file
    std::ifstream fin;
    fin.open(filename.c_str());

    std::string tmp_string;


    // skipping desc
    getline(fin, tmp_string, '\n');
    std::string string_desc = tmp_string.substr(0, 4);

    if (string_desc.compare("desc")) {
        std::string str("error: no desc");
        throw WorkflowException(str);
        return;
    }


    // reading commands
    const int max_commands = 1000;
    int commands = 0;
    getline(fin, tmp_string, '\n');
    std::vector<int> numbers;
    while (tmp_string.compare("csed\n") && tmp_string.compare("csed\r") && tmp_string.compare("csed") && commands < max_commands) {
        // checking for number

        int i = 0;
        while (i < tmp_string.size() && tmp_string.at(i) != ' ') {
            i++;
        }
        std::string str_number = tmp_string.substr(0, i);
        if (isdigit(str_number.at(0))) {
            int number = stoi(str_number);
            numbers.push_back(number);
        }
        for(int j = 0; j < str_number.size(); j++) {
            if (!isdigit(str_number.at(j))) {
                std::string str("error: sequence is not all numbers");
                throw WorkflowException(str);
                return;
            }
        }

        // checking for =
        i++;
        if (i < tmp_string.size() && tmp_string.at(i) != '=') {
            std::string str("error: no =");
            throw WorkflowException(str);
            return;
        }
        i++;
        i++;

        // checking for proper command
        int start = i;
        if (i >= tmp_string.size()) {
            std::string str("error: no command");
            throw WorkflowException(str);
            return;
        }
        while(i < tmp_string.size() && tmp_string.at(i) != ' ' && tmp_string.at(i) != '\n' && tmp_string.at(i) != '\r') {
            i++;
            if (i >= tmp_string.size()) {
                break;
            }
        }
        std::string command = tmp_string.substr(start, i - start);

        //std::cout << command << std::endl;
        if (command.compare("readfile") && command.compare("writefile") && command.compare("grep") && command.compare("sort") && command.compare("replace") && command.compare("dump")) {
            std::string str("error: invalid command");
            throw WorkflowException(str);
            return;
        }

        commands++;
        if (fin.eof()) {
            std::string str("error: no csed");
            throw WorkflowException(str);
            return;
        }

        getline(fin, tmp_string, '\n');
    }


    // reading sequence
    getline(fin, tmp_string, '\n');
    for (int j = 0; j < tmp_string.size(); j++) {
        if (tmp_string.at(j) == '>' && tmp_string.at(j - 1) != '-') {
            std::string str("error: invalid sequence");
            throw WorkflowException(str);
        }
        else if (!isdigit(tmp_string.at(j)) && tmp_string.at(j) != ' ' && tmp_string.at(j) != '\r' && tmp_string.at(j) != '\n' && tmp_string.at(j) != '-' && tmp_string.at(j) != '>') {
            std::string str("error: invalid sequence");
            throw WorkflowException(str);
        }
    }

    std::vector<int> seq = get_sequence(tmp_string);
    for (int j = 0; j < seq.size(); j++) {
        bool is_in = false;
        for (int k = 0; k < numbers.size(); k++) {
            if (numbers.at(k) == seq.at(j)) {
                is_in = true;
            }
        }
        if(!is_in) {
            std::string str("error: invalid sequence");
            throw WorkflowException(str);
        }
    }

    fin.close();
}

WorkflowException::WorkflowException(std::string &err_massage) : error{err_massage} {}

const char* WorkflowException::what() {
    return error.c_str();
}
