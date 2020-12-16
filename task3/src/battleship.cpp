#include "battleship.h"

bool is_number(const std::string s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// ####################################   Game  ###################################

Game::Game() {
    std::cout << "Welcome, to the sea battle!" << std::endl;

    // TODO: ALL FUNCTION
}

bool Game::is_over() {
    return (p1_score + p2_score >= number_of_rounds);
}


// ##############################   Interface player  #############################

bool IPlayer::is_dead() {
    if (health <= 0) {
        return true;
    }
    return false;
}

bool IPlayer::is_there(int x, int y) {
    if (own_matrix.at(y).at(x) == 'S') {
        return true;
    }
    return false;
}

bool IPlayer::get_shot(int x, int y) {      // returns true if ship is destroyed
    own_matrix.at(y).at(x) = 'X';
    health--;

    // MAYBE THERE IS A MISTAKE
    if ((y > 0 && own_matrix.at(y - 1).at(x) == 'S') || (y < 9 && own_matrix.at(y + 1).at(x) == 'S') || (x > 0 && own_matrix.at(y).at(x - 1) == 'S') || (x < 9 && own_matrix.at(y).at(x + 1) == 'S')) {
        return false;
    }

    if (y > 0 && own_matrix.at(y - 1).at(x) == 'X') {
        int i = 2;
        while (y - i >= 0 && own_matrix.at(y - i).at(x) == 'X') i++;
        if (own_matrix.at(y - i).at(x) == 'S') {
            return true;
        }
    }
    if (y < 9 && own_matrix.at(y + 1).at(x) == 'X') {
        int i = 2;
        while (y + i <= 9 && own_matrix.at(y + i).at(x) == 'X') i++;
        if (own_matrix.at(y + i).at(x) == 'S') {
            return true;
        }
    }
    if (x > 0 && own_matrix.at(y).at(x - 1) == 'X') {
        int i = 2;
        while (x - i >= 0 && own_matrix.at(y).at(x - i) == 'X') i++;
        if (own_matrix.at(y).at(x - i) == 'S') {
            return true;
        }
    }
    if (x < 9 && own_matrix.at(y).at(x + 1) == 'X') {
        int i = 2;
        while (x + i <= 9 && own_matrix.at(y).at(x + i) == 'X') i++;
        if (own_matrix.at(y).at(x + i) == 'S') {
            return true;
        }
    }

    return false;
}

bool IPlayer::set_ship(int x1, int y1, int x2, int y2) {

    // checking if coordinates are out of range
    if (x1 < 0 || x1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y1 > 9 || y2 < 0 || y2 > 9) {
        return false;
    }
    // checking if ship is diagonal
    else if (x1 != x2 && y1 != y2) {
        return false;
    }
    // checking if it will collide another ship
    if (x1 == x2) {
        int i = 0;
        while (std::min(y1, y2) + i <= std::max(y1, y2)) {
            if (own_matrix.at(std::min(y1, y2) + i).at(x1) == 'S') return false;
            i++;
        }
    }
    else if (y1 == y2) {
        int i = 0;
        while (std::min(x1, x2) + i < std::max(x1, x2)) {
            if (own_matrix.at(y1).at(std::min(x1, x2) + i) == 'S') return false;
            i++;
        }
    }

    // setting a ship
    if (x1 == x2) {
        int i = 0;
        while (std::min(y1, y2) + i <= std::max(y1, y2)) {
            own_matrix.at(std::min(y1, y2) + i).at(x1) = 'S';
            i++;
        }
    }
    else if (y1 == y2) {
        int i = 0;
        while (std::min(x1, x2) + i <= std::max(x1, x2)) {
            own_matrix.at(y1).at(std::min(x1, x2) + i) = 'S';
            i++;
        }
    }

    return true;
}

int IPlayer::ship_len(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        return std::abs(y1 - y2) + 1;
    }
    return std::abs(x1 - x2) + 1;
}

void IPlayer::print_matrix(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << own_matrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

// ##############################   Console player  #############################

ConsolePlayer::ConsolePlayer() {
    // setting name
    std::cout << "Type player name: ";
    std::cin >> name;

    // setting health
    health = 20;

    // setting matrix / game boards
    std::vector<char> tmp_vector;
    for (int i = 0; i < BOARD_SIZE; i++) {
        tmp_vector.push_back('~');
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        opponent_matrix.push_back(tmp_vector);
        own_matrix.push_back(tmp_vector);
    }
}   

bool ConsolePlayer::make_move(IPlayer& enemy) {     // return true if needs one more move
    std::cout << name << "'s turn!" << std::endl;

    // getting coordinates to hit
    bool is_valid = false;
    std::pair<int, int> coordinates;
    while (!is_valid) {
        std::cout << "Fire in sector: ";
        std::cin >> coordinates.first >> coordinates.second;
        coordinates.first--;
        coordinates.second--;

        if (coordinates.first >= 0 && coordinates.first <= 9 && coordinates.second >= 0 && coordinates.second <= 9) is_valid = true;
        else {
            std::cout << "Invalid coordinates, sir." << std::endl;
        }
    }

    // if hit
    if (enemy.is_there(coordinates.first, coordinates.second)) {
        opponent_matrix.at(coordinates.second).at(coordinates.first) = 'X';
        if (enemy.get_shot(coordinates.first, coordinates.second)) {
            std::cout << "Ship is destroyed!" << std::endl;
        }
        else {
            std::cout << "Hit!" << std::endl;
        }
        return true;
    }
    // if missed
    else {
        opponent_matrix.at(coordinates.second).at(coordinates.second) = '*';
        std::cout << "Miss" << std::endl;
    }

    return false;
}

void ConsolePlayer::arrange_board() {

    std::cout << std::endl << "You have 10 ships to set:" << std::endl;
    std::cout << "1 four-deck" << std::endl;
    std::cout << "2 three-deck" << std::endl;
    std::cout << "3 two-deck" << std::endl;
    std::cout << "4 single-deck" << std::endl;

    int x1, x2, y1, y2;
    std::cout << "Let's start with four-deck one" << std::endl;
    std::cout << "Enter coordinates of first end: ";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of second end: ";
    std::cin >> x2 >> y2;
    while (!set_ship(x1, y1, x2, y2) || ship_len(x1, y1, x2, y2) != 4) {
        std::cout << std::endl << "Invalid coordinates." << std::endl;
        std::cout << "Arrange four-deck ship" << std::endl;
        std::cout << "Enter coordinates of first end: ";
        std::cin >> x1 >> y1;
        std::cout << "Enter coordinates of second end: ";
        std::cin >> x2 >> y2;
    }

    for (int i = 0; i < 2; i++) {
        std::cout << "Now set three-deck's ship" << std::endl;
        std::cout << "Enter coordinates of first end: ";
        std::cin >> x1 >> y1;
        std::cout << "Enter coordinates of second end: ";
        std::cin >> x2 >> y2;
        while (!set_ship(x1, y1, x2, y2) || ship_len(x1, y1, x2, y2) != 3) {
            std::cout << std::endl << "Invalid coordinates." << std::endl;
            std::cout << "Arrange three-deck ship" << std::endl;
            std::cout << "Enter coordinates of first end: ";
            std::cin >> x1 >> y1;
            std::cout << "Enter coordinates of second end: ";
            std::cin >> x2 >> y2;
        }
    }

    for (int i = 0; i < 3; i++) {
        std::cout << "Now set two-deck's ship" << std::endl;
        std::cout << "Enter coordinates of first end: ";
        std::cin >> x1 >> y1;
        std::cout << "Enter coordinates of second end: ";
        std::cin >> x2 >> y2;
        while (!set_ship(x1, y1, x2, y2) || ship_len(x1, y1, x2, y2) != 2) {
            std::cout << std::endl << "Invalid coordinates." << std::endl;
            std::cout << "Arrange two-deck ship" << std::endl;
            std::cout << "Enter coordinates of first end: ";
            std::cin >> x1 >> y1;
            std::cout << "Enter coordinates of second end: ";
            std::cin >> x2 >> y2;
        }
    }

    for (int i = 0; i < 4; i++) {
        std::cout << "Set single-deck ship with one coordinate" << std::endl;
        std::cout << "Enter coordinate: ";
        std::cin >> x1 >> y1;
        y2 = y1;
        x2 = x1;
        while (!set_ship(x1, y1, x2, y2)) {
            std::cout << std::endl << "Invalid coordinates." << std::endl;
            std::cout << "Enter new coordinate: ";
            std::cin >> x1 >> y1;
            y2 = y1;
            x2 = x1;
        }
    }

}



