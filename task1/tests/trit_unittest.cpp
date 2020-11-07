#include "../src/trit.cpp"
#include "gtest/gtest.h"

TEST(TritSet, constructor) {
    // arrange
    TritSet set(1);

    //assert
    EXPECT_EQ(Trit::True, TritSet::get_two_bits(0b00110000, 1));
}

TEST(TritSet, get_trit) {
    // arrange
    TritSet set(1);

    //assert
    EXPECT_EQ(set.get_trit(0), Trit::Unknown);
    EXPECT_EQ(set.get_trit(1), Trit::Unknown);
    EXPECT_EQ(set.get_trit(2), Trit::Unknown);
    EXPECT_EQ(set.get_trit(3), Trit::Unknown);
}

TEST(TritSet, operator_index) {
    // arrange
    TritSet set(8);

    // act
    set[0] = Trit::True;              // (true, false, false, unknown, true, true, unknown, false)
    set[1] = Trit::False;
    set[2] = Trit::False;
    set[3] = Trit::Unknown;

    set[4] = Trit::True;
    set[5] = Trit::True;
    set[6] = Trit::Unknown;
    set[7] = Trit::False;

    // assert
    EXPECT_EQ((Trit(set[0])), Trit::True);
    EXPECT_EQ(set.get_trit(0), Trit::True);

    EXPECT_EQ((Trit(set[1])), Trit::False);
    EXPECT_EQ(set.get_trit(1), Trit::False);

    EXPECT_EQ((Trit(set[2])), Trit::False);
    EXPECT_EQ(set.get_trit(2), Trit::False);

    EXPECT_EQ((Trit(set[3])), Trit::Unknown);
    EXPECT_EQ(set.get_trit(3), Trit::Unknown);

    EXPECT_EQ((Trit(set[4])), Trit::True);
    EXPECT_EQ(set.get_trit(4), Trit::True);

    EXPECT_EQ((Trit(set[5])), Trit::True);
    EXPECT_EQ(set.get_trit(5), Trit::True);

    EXPECT_EQ((Trit(set[6])), Trit::Unknown);
    EXPECT_EQ(set.get_trit(6), Trit::Unknown);

    EXPECT_EQ((Trit(set[7])), Trit::False);
    EXPECT_EQ(set.get_trit(7), Trit::False);
}

TEST(TritSet, get_two_bits) {
    // arrange
    uint8_t byte = 0b00011011;

    // assert
    EXPECT_EQ(TritSet::get_two_bits(byte, 0), Trit::False);
    EXPECT_EQ(TritSet::get_two_bits(byte, 1), Trit::Unknown);
    EXPECT_EQ(TritSet::get_two_bits(byte, 2), Trit::Unknown);
    EXPECT_EQ(TritSet::get_two_bits(byte, 3), Trit::True);
}


/*TEST(TritSet, get_trit) {
    // arrange

    // act

    // assert
}*/





TEST(TritSet_index, simple_test) {
    // arrange
    TritSet set(4);
    Trit res = set.get_trit(1);

    //assert
    EXPECT_EQ(res, Trit::Unknown);
}

TEST(TritSet_index, second_bit) {
    // arrange
    TritSet set(6);
    Trit res = set.get_trit(5);

    //assert
    EXPECT_EQ(res, Trit::Unknown);
}

TEST(TritSet_index, unknowngs_test) {
    // arrange
    uint8_t array[2];
    array[0] = 0b01110101;

    // act
    Trit res = TritSet::get_two_bits(array[0], 1);

    //assert
    EXPECT_EQ(res, Trit::True);
}
