#include "../src/battleship.cpp"
#include "gtest/gtest.h"

TEST(Ship_len, simple_test) {
    // arrange
    ConsolePlayer player;

    // act
    EXPECT_EQ(player.ship_len(0, 0, 0, 0), 1);
    EXPECT_EQ(player.ship_len(3, 4, 3, 4), 1);

    EXPECT_EQ(player.ship_len(0, 0, 0, 1), 2);
    EXPECT_EQ(player.ship_len(0, 0, 1, 0), 2);

    EXPECT_EQ(player.ship_len(0, 0, 0, 2), 3);
    EXPECT_EQ(player.ship_len(0, 0, 2, 0), 3);

    EXPECT_EQ(player.ship_len(0, 0, 0, 3), 4);
    EXPECT_EQ(player.ship_len(0, 0, 3, 0), 4);

    EXPECT_EQ(player.ship_len(1, 1, 1, 4), 4);
    EXPECT_EQ(player.ship_len(1, 1, 4, 1), 4);

    // assert
}

TEST(Play_game, game) {
    // arrange
    ConsolePlayer player1;
    player1.arrange_board();
    ConsolePlayer player2;
    player2.arrange_board();

    Game game(&player1, &player2);
    game.play_game();

    // act

    // assert
}


/*TEST(Make_move, simple_test) {
    // arrange
    ConsolePlayer player;

    // act
    player.arrange_board();
    player.print_matrix();

    // assert
}*/

/*TEST(Executor_index, simple_test) {
    // arrange

    // act

    // assert
}*/
