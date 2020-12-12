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
    if (own_matrix[x][y] == 'S') {
        return true;
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

std::pair<int, int> ConsolePlayer::get_coordinates(std::string string) {
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
    const char *x_char = x_str.c_str();

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

    if (!is_number(y_str) || !(*x_char > 'z' && *x_char < 'a')) {
        return coordinates;
    }
    int x = atoi(x_char);
    int y = stoi(y_str);

    coordinates.first = x;
    coordinates.second = y;

    return coordinates;
}

void ConsolePlayer::make_move() {
    std::cout << "Your turn!" << std::endl;

    // getting coordinates to hit
    bool is_valid = false;
    std::pair<int, int> coordinates;
    while (!is_valid) {
        std::cout << "Fire in sector: ";
        std::string input_string;
        getline(std::cin, input_string, '\n');

        coordinates = get_coordinates(input_string);

        if (coordinates.first != 0) is_valid = true;
    }
}
