#include "../src/battleship.cpp"
#include "gtest/gtest.h"

/*TEST(random_game, game) {
    // arrange
    ConsoleView game_view;
    RandomPlayer player(&game_view);
    player.arrange_board();
    player.print_matrix();

    // act

    // assert
}*/

TEST(Ship_len, simple_test) {
    // arrange
    ConsoleView game_view;
    ConsolePlayer player(&game_view);

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
    ConsoleView game_view;
    OptimalPlayer player1(&game_view);
    player1.arrange_board();
    ConsolePlayer player2(&game_view);
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
