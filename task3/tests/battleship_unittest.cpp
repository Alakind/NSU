#include "../src/battleship.cpp"
#include "gtest/gtest.h"

/*TEST(Get_coordinates, simple_test) {
    // arrange
    ConsolePlayer player;

    // act
    std::pair<int, int> coordinates (-1, -1);
    coordinates = player.get_coordinates("1 2");

    // assert
    EXPECT_EQ(coordinates.first, 0);
    EXPECT_EQ(coordinates.second, 1);
}*/

TEST(Make_move, simple_test) {
    // arrange
    ConsolePlayer player;
    ConsolePlayer op_player;

    // act
    player.make_move(op_player);

    // assert
}

/*TEST(Executor_index, simple_test) {
    // arrange

    // act

    // assert
}*/
