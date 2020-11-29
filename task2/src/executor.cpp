#include "executor.h"

Readfile::Readfile(char* filename) {
    std::string filename_str = filename;
    file_name = filename_str;
}

std::vector<std::string> Readfile::execute(std::vector<std::string> &text) {
    std::ifstream fin;
    fin.open(this->file_name);

    std::string tmp_string;
    while(!fin.eof()) {
        getline(fin, tmp_string, '\n');
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
