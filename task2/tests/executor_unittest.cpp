#include "../src/executor.cpp"
#include "gtest/gtest.h"

TEST(Readfile, text_in_file) {
    // arrange
    std::ofstream fout;
    char* filename = (char*) "text.txt";
    fout.open(filename);

    fout << "Hello, i am text massage checking testing bip-bop" << std::endl << "Haha new line";

    Readfile doer(filename);

    fout.close();

    std::vector<std::string> text;

    // act
    doer.execute(text);

    // assert
    if (text.at(0).compare("Hello, i am text massage checking testing bip-bop")) {
        FAIL();
    }if (text.at(1).compare("Haha new line")) {
        FAIL();
    }

    remove(filename);
}

TEST(Writefile, text_in_file) {
    // arrange
    std::vector<std::string> text = {"Hello, i am text massage checking testing bip-bop", "Haha new line"};

    std::ofstream fout;
    char* filename = (char*) "text.txt";
    fout.open(filename);

    Writefile writer(filename);

    // act
    writer.execute(text);

    fout.close();

    // assert
    std::ifstream fin;
    fin.open(filename);
    std::string tmp_string;

    getline(fin, tmp_string, '\n');
    if (tmp_string.compare("Hello, i am text massage checking testing bip-bop")) {
        FAIL();
    }
    getline(fin, tmp_string, '\n');
    if (tmp_string.compare("Haha new line")) {
        FAIL();
    }

    fin.close();
    remove(filename);
}

TEST(Executor_index, simple_test) {
    // arrange

    // act

    // assert
}
