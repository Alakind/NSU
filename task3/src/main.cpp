#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <exception>
#include "battleship.h"


int main(int argc, char* argv[]) {


    PlayerType player1_type;
    PlayerType player2_type;

    switch (player1_type) {
    case PlayerType::type_optimal:
        //OptimalPlayer* player1 = new OptimalPlayer;           TODO: OPTIMALPLAYER
        break;
    case PlayerType::type_console:
        ConsolePlayer* player1;
        break;
    default:    // default - random player
        //RandomPlayer* player1 = new RandomPlayer;             TODO: RANDOMPLAYER
        break;
    }

    switch (player2_type) {
    case PlayerType::type_optimal:
        //OptimalPlayer* player2 = new OptimalPlayer;           TODO: OPTIMALPLAYER
        break;
    case PlayerType::type_console:
        ConsolePlayer* player2;
        break;
    default:    // default - random player
        //RandomPlayer* player2 = new RandomPlayer;             TODO: RANDOMPLAYER
        break;
    }

    return 0;
}
