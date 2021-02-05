#include "../src/trit.cpp"
#include "gtest/gtest.h"

TEST(TritSet, constructor1) {
    // arrange
    TritSet set(1);

    //assert
    EXPECT_EQ(Trit::True, TritSet::get_two_bits(0b00110000, 1));
}

TEST(TritSet, constructor2) {
    // arrange
    TritSet set(8);

    //assert
    EXPECT_EQ(Trit(set[0]), Trit::Unknown);
    EXPECT_EQ(Trit(set[1]), Trit::Unknown);
    EXPECT_EQ(Trit(set[2]), Trit::Unknown);
    EXPECT_EQ(Trit(set[3]), Trit::Unknown);
    EXPECT_EQ(Trit(set[4]), Trit::Unknown);
    EXPECT_EQ(Trit(set[5]), Trit::Unknown);
    EXPECT_EQ(Trit(set[6]), Trit::Unknown);
    EXPECT_EQ(Trit(set[7]), Trit::Unknown);
    EXPECT_EQ(Trit(set[8]), Trit::Unknown);
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

TEST(TritSet, get_capacity) {
    // arrange
    TritSet set1(0);
    TritSet set2(4);
    TritSet set3(6);
    TritSet set4(1000);

    // assert
    EXPECT_EQ(set1.get_capacity(), 0);
    EXPECT_EQ(set2.get_capacity(), 4);
    EXPECT_EQ(set3.get_capacity(), 6);
    EXPECT_EQ(set4.get_capacity(), 1000);
}

TEST(TritSet, expand) {
    // arrange
    TritSet set(5);

    // act
    set[9] = Trit::True;

    // assert
    EXPECT_EQ(Trit(set[8]), Trit::Unknown);
    EXPECT_EQ(Trit(set[9]), Trit::True);
    EXPECT_EQ(Trit(set[10]), Trit::Unknown);
    EXPECT_EQ(Trit(set[11]), Trit::Unknown);
}

TEST(TritSet, shrink) {
    // arrange
    TritSet set(11);
    set[9] = Trit::True;

    EXPECT_EQ(Trit(set[5]), Trit::Unknown);
    EXPECT_EQ(Trit(set[9]), Trit::True);

    // act
    set.shrink(6);

    // assert
    EXPECT_EQ(Trit(set[5]), Trit::Unknown);
    EXPECT_EQ(Trit(set[9]), Trit::Unknown);
}

TEST(TritSet, operator_and) {
    // arrange
    TritSet set1(10);
    TritSet set2(10);

    set1[0] = Trit::True;
    set1[1] = Trit::True;
    set1[2] = Trit::True;
    set1[3] = Trit::False;
    set1[4] = Trit::False;
    set1[5] = Trit::Unknown;

    set2[0] = Trit::True;
    set2[1] = Trit::False;
    set2[2] = Trit::Unknown;
    set2[3] = Trit::False;
    set2[4] = Trit::Unknown;
    set2[5] = Trit::Unknown;

    // act
    set1 & set2;

    // assert
    EXPECT_EQ(Trit(set1[0]), Trit::True);
    EXPECT_EQ(Trit(set1[1]), Trit::False);
    EXPECT_EQ(Trit(set1[2]), Trit::Unknown);
    EXPECT_EQ(Trit(set1[3]), Trit::False);
    EXPECT_EQ(Trit(set1[4]), Trit::False);
    EXPECT_EQ(Trit(set1[5]), Trit::Unknown);
}

TEST(TritSet, operator_or) {
    // arrange
    TritSet set1(10);
    TritSet set2(10);

    set1[0] = Trit::True;
    set1[1] = Trit::True;
    set1[2] = Trit::True;
    set1[3] = Trit::False;
    set1[4] = Trit::False;
    set1[5] = Trit::Unknown;

    set2[0] = Trit::True;
    set2[1] = Trit::False;
    set2[2] = Trit::Unknown;
    set2[3] = Trit::False;
    set2[4] = Trit::Unknown;
    set2[5] = Trit::Unknown;

    // act
    set1 | set2;

    // assert
    EXPECT_EQ(Trit(set1[0]), Trit::True);
    EXPECT_EQ(Trit(set1[1]), Trit::True);
    EXPECT_EQ(Trit(set1[2]), Trit::True);
    EXPECT_EQ(Trit(set1[3]), Trit::False);
    EXPECT_EQ(Trit(set1[4]), Trit::Unknown);
    EXPECT_EQ(Trit(set1[5]), Trit::Unknown);
}

TEST(TritSet, operator_not) {
    // arrange
    TritSet set(10);

    set[0] = Trit::True;
    set[1] = Trit::False;
    set[2] = Trit::Unknown;

    // act
    ~set;

    // assert
    EXPECT_EQ(Trit(set[0]), Trit::False);
    EXPECT_EQ(Trit(set[1]), Trit::True);
    EXPECT_EQ(Trit(set[2]), Trit::Unknown);
}

TEST(TritProxy, operator_equality) {
    // arrange
    TritSet set(4);
    set[1] = Trit::True;
    set[2] = Trit::False;

    TritSet::TritProxy proxy_unknown(set, 0);
    TritSet::TritProxy proxy_true(set, 1);
    TritSet::TritProxy proxy_false(set, 2);

    // assert
    EXPECT_EQ(proxy_unknown == Trit::Unknown, true);
    EXPECT_EQ(proxy_unknown == Trit::True, false);
    EXPECT_EQ(proxy_unknown == Trit::False, false);

    EXPECT_EQ(proxy_true == Trit::Unknown, false);
    EXPECT_EQ(proxy_true == Trit::True, true);
    EXPECT_EQ(proxy_true == Trit::False, false);

    EXPECT_EQ(proxy_false == Trit::Unknown, false);
    EXPECT_EQ(proxy_false == Trit::True, false);
    EXPECT_EQ(proxy_false == Trit::False, true);
}

TEST(TritProxy, operator_not_equality) {
    // arrange
    TritSet set(4);
    set[1] = Trit::True;
    set[2] = Trit::False;

    TritSet::TritProxy proxy_unknown(set, 0);
    TritSet::TritProxy proxy_true(set, 1);
    TritSet::TritProxy proxy_false(set, 2);

    // assert
    EXPECT_EQ(proxy_unknown != Trit::Unknown, false);
    EXPECT_EQ(proxy_unknown != Trit::True, true);
    EXPECT_EQ(proxy_unknown != Trit::False, true);

    EXPECT_EQ(proxy_true != Trit::Unknown, true);
    EXPECT_EQ(proxy_true != Trit::True, false);
    EXPECT_EQ(proxy_true != Trit::False, true);

    EXPECT_EQ(proxy_false != Trit::Unknown, true);
    EXPECT_EQ(proxy_false != Trit::True, true);
    EXPECT_EQ(proxy_false != Trit::False, false);
}



/*TEST(TritSet_index, simple_test) {
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

TEST(TritSet_index, unknowns_test) {
    // arrange
    uint8_t array[2];
    array[0] = 0b01110101;

    // act
    Trit res = TritSet::get_two_bits(array[0], 1);

    //assert
    EXPECT_EQ(res, Trit::True);
}*/
