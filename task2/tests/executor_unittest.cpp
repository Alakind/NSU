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
    // act

    // assert
}

TEST(Executor_index, simple_test) {
    // arrange

    // act

    // assert
}
