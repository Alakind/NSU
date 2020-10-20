#include <src/trit.h>
#include "gtest/gtest.h"

TEST(plusten_func, simpletest_ok) {
    EXPECT_EQ(10, plus_ten(0));
}

TEST(plusten_func, simpletest_error) {
    EXPECT_EQ(12, plus_ten(0));
}

/*TEST(CRC32_function, EmptymWord)
{
    // arrange
    char test_char[256] = "";

    // act
    uint32_t res = CRC32_function((unsigned char *) test_char, strlen(test_char), 0);

    // assert посчитано на http://www.codenet.ru/services/crc32/
    EXPECT_EQ(0, res);
}

TEST(CRC32_function, RandomWord)
{
    // arrange
    char test_char[256] = "random";

    // act
    uint32_t res = CRC32_function((unsigned char *) test_char, strlen(test_char), 0);

    // assert посчитано на http://www.codenet.ru/services/crc32/
    EXPECT_EQ(373021397, res);
}

TEST(SUM32_function, EmptyWord)
{
    // arrange
    char test_char[256] = "";

    // act
    uint32_t res = SUM32_function((unsigned char *) test_char, strlen(test_char), 0);

    // assert, посчитано с помощью Python
    EXPECT_EQ(0, res);
}

TEST(SUM32_function, RandomWord)
{
    // arrange
    char test_char[256] = "random";

    // act
    uint32_t res = SUM32_function((unsigned char *) test_char, strlen(test_char), 0);

    // assert, посчитано с помощью Python
    EXPECT_EQ(1852105166, res);
}

TEST(SUM32_function, WordOf64Size)
{
    // arrange
    char test_char[256] = "aaaaaaaa";

    // act
    uint32_t res = SUM32_function((unsigned char *) test_char, strlen(test_char), 0);

    // assert, посчитано с помощью Python
    EXPECT_EQ(3267543746, res);
}

TEST(SUM32_function, WordOf72Size)
{
    // arrange
    char test_char[256] = "aaaaaaaaa";

    // act
    uint32_t res = SUM32_function((unsigned char *) test_char, strlen(test_char), 0);

    // assert, посчитано с помощью Python
    EXPECT_EQ(3267543843, res);
}*/
