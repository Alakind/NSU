#include "../src/trit.cpp"
#include "gtest/gtest.h"

TEST(TritSet_get_two_bits, simple_test) {
    EXPECT_EQ(Trit::True, get_two_bits(0b00110000, 1));
}

TEST(TritSet_get_two_bits, simple_test) {
    TritSet set(5);

    EXPECT_EQ();
}

TEST(tritSet_class, tritSet_constructor) {
    // arrange
    TritSet set(1);

    // act
    uint8_t result_mask1 = 0b01010101;

    //assert
    //EXPECT_EQ(set.array[0], result_mask1);        // tak blin peregruzi
}
