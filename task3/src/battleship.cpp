#include "battleship.h"

// ##############################   Console player  #############################

ConsolePlayer::ConsolePlayer() {
    // setting name
    std::cout << "Type players name: ";
    std::cin >> name;

    // setting health
    health = 20;

    // setting matrix / game boards
    std::vector<char> tmp_vector;
    for (int i = 0; i < 10; i++) {
        tmp_vector.push_back('~');
    }
    for (int i = 0; i < 10; i++) {
        opponent_matrix.push_back(tmp_vector);
        own_matrix.push_back(tmp_vector);
    }
}
