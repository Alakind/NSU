#include "../src/executor.cpp"
#include "gtest/gtest.h"

TEST(Readfile, text_in_file) {
    // arrange
    std::ofstream fout;
    char* filename = (char*) "text_test.txt";
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
    char* filename = (char*) "text_test.txt";
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

TEST(Grep, simple_test) {
    // arrange
    std::vector<std::string> text = {"a bc a fs", "heh aaa", "lookn for a a a", "parkour! aa", "a", "hm baaab"};

    char* word = (char*) "aaa";

    Grep greper(word);

    // act
    greper.execute(text);

    // assert
    if (text.at(0).compare("heh aaa")) {
        FAIL();
    }if (text.at(1).compare("hm baaab")) {
        FAIL();
    }
}

TEST(Sort, simple_test) {
    // arrange
    std::vector<std::string> text = {"a bc a fs", "heh aaa", "lookn for a a a", "parkour! aa", "a", "hm baaab"};

    Sort sorter;

    // act
    sorter.execute(text);

    // assert
    if (text.at(0).compare("a")) {
        FAIL();
    }if (text.at(1).compare("a bc a fs")) {
        FAIL();
    }if (text.at(2).compare("heh aaa")) {
        FAIL();
    }if (text.at(3).compare("hm baaab")) {
        FAIL();
    }if (text.at(4).compare("lookn for a a a")) {
        FAIL();
    }if (text.at(5).compare("parkour! aa")) {
        FAIL();
    }
}

TEST(Replace, simple_test) {
    // arrange
    std::vector<std::string> text = {"a bc a fs", "heh aaa", "lookn for a a a", "parkour! aa", "a", "hm baaab"};

    char* word_from = (char*) "aaa";
    char* word_to = (char*) "lol";

    Replace replacer(word_from, word_to);

    // act
    replacer.execute(text);

    // assert
    if (text.at(0).compare("a bc a fs")) {
        FAIL();
    }if (text.at(1).compare("heh lol")) {
        FAIL();
    }if (text.at(2).compare("lookn for a a a")) {
        FAIL();
    }if (text.at(3).compare("parkour! aa")) {
        FAIL();
    }if (text.at(4).compare("a")) {
        FAIL();
    }if (text.at(5).compare("hm blolb")) {
        FAIL();
    }
}

TEST(Take_command, simple_test) {
    // arrange
    std::string string = "25 = commander haha hehe\n";

    // act
    std::pair<int, std::string> res_pair = get_block(string);

    // assert
    EXPECT_EQ(25, res_pair.first);
    EXPECT_EQ("commander haha hehe", res_pair.second);
}

TEST(Get_sequence, simple_test) {
    // arrange
    std::string string = "25 -> 12 -> 54 -> 0 -> 1";

    // act
    std::vector<int> seq = get_sequence(string);

    // assert
    EXPECT_EQ(seq.at(0), 25);
    EXPECT_EQ(seq.at(1), 12);
    EXPECT_EQ(seq.at(2), 54);
    EXPECT_EQ(seq.at(3), 0);
    EXPECT_EQ(seq.at(4), 1);
    
}

TEST(Test_workflow, simple_test) {
    // arrange
    

    // act
    workflow_execute((char*)"workflow0.txt");

    // assert
    
}

/*TEST(Executor_index, simple_test) {
    // arrange

    // act

    // assert
}*/
