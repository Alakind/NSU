#include "../src/trit.cpp"
#include "gtest/gtest.h"

TEST(TritSet_get_two_bits, simple_test) {
    // arrange
    TritSet set(1);

    //assert
    EXPECT_EQ(Trit::True, TritSet::get_two_bits(0b00110000, 1));
}

TEST(TritSet_index, simple_test) {
    // arrange
    TritSet set(4);
    Trit res = set[1];

    //assert
    EXPECT_EQ(res, Trit::Unknown);
}

TEST(TritSet_index, second_bit) {
    // arrange
    TritSet set(6);
    Trit res = set[5];

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

TEST(tritSet_class, tritSet_constructor) {
    // arrange
    TritSet set(1);

    // act
    uint8_t result_mask1 = 0b01010101;

    //assert
    //EXPECT_EQ(set.array[0], result_mask1);        // tak blin peregruzi
}
