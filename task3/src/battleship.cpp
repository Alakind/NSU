#include "battleship.h"

bool is_number(const std::string s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
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

/*std::pair<int, int> ConsolePlayer::get_coordinates(std::string string) {
    std::pair<int, int> coordinates (-1, -1);

    int i = 0;
    std::string x_str;
    if (i < string.size() && string.at(i) != '\n' && string.at(i) != '\r') {
        i++;
        while(string.at(i) != ' ' && string.at(i) != '\n' && string.at(i) != '\r') {
            i++;
            if (i >= string.size()) {
                break;
            }
        }
        x_str = string.substr(0, i);
    }

    int start = i + 1;
    std::string y_str;
    if (i < string.size() && string.at(i) != '\n' && string.at(i) != '\r') {
        i++;
        while(string.at(i) != ' ' && string.at(i) != '\n' && string.at(i) != '\r') {
            i++;
            if (i >= string.size()) {
                break;
            }
        }
        y_str = string.substr(start, i - start);
    }

    if (!is_number(y_str) || !is_number(x_str)) {
        return coordinates;
    }
    int x = stoi(x_str);
    int y = stoi(y_str);

    coordinates.first = x - 1;
    coordinates.second = y - 1;

    return coordinates;
}*/

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
            std::cout << "Invalid coordinates, sir!" << std::endl;
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


