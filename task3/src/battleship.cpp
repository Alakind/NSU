#include "battleship.h"

bool is_number(const std::string s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::pair<int, int> get_coordinates_rand() {
    std::srand(time(0));
    std::pair<int, int> coordinates = {-1, -1};
    coordinates.first = (std::rand() % 10);
    coordinates.second = (std::rand() % 10);

    return coordinates;
}

std::pair<int, int> get_coordinates_cin() {
    char in_string_char[100];
    std::string in_string;
    std::getline(std::cin, in_string);


    std::pair<int, int> coordinates = {-1, -1};

    int spaces = 0;
    int second_start = 2;
    for (int i = 0; i < in_string.length(); i++) {
        if (in_string.at(i) == ' ') {
            spaces++;
            second_start = i + 1;
            continue;
        }
        if (!isdigit(in_string.at(i)) || spaces > 1 || second_start - 2 < 0) {
            return coordinates;
        }
    }
    if (spaces == 0) {
        return coordinates;
    }

    coordinates.first = stoi(in_string.substr(0, second_start - 1));
    coordinates.second = stoi(in_string.substr(second_start));
    coordinates.first--;
    coordinates.second--;

    return coordinates;
}

// ####################################  Game  ####################################

Game::Game(IPlayer* player1_in, IPlayer* player2_in) {
    p1_score = 0;
    p2_score = 0;
    player1 = player1_in;
    player2 = player2_in;

    std::cout << "Welcome to Battleship: the game" << std::endl;

    std::cout << "Enter number of rounds to play: ";
    std::cin >> number_of_rounds;
}

bool Game::is_over() {
    return (p1_score + p2_score >= number_of_rounds);
}

void Game::play_game() {
    std::cout << "Game started!" << std::endl;
    for (int rounds_played = 0; rounds_played < number_of_rounds; rounds_played++) {
        std::cout << player1->name << " score: " << p1_score << std::endl << player2->name << " score: " << p2_score << std::endl << "rounds to go: " << number_of_rounds - rounds_played << std::endl;
        if (play_round()) {
            p1_score++;
        }
        else {
            p2_score++;
        }
    }
    if (p1_score > p2_score) {
        std::cout << player1->name << " wins!" << std::endl;
    }
}

bool Game::play_round() {
    std::cout << "New round started" << std::endl;
    while (!player1->is_dead() && !player2->is_dead()) {
        while (player1->make_move(*player2));
        if (player2->is_dead()) break;
        while (player2->make_move(*player1));
    }
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
    own_matrix.at(y).at(x) = 'T';
    health--;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            if ((y + dy >= 0 && y + dy <= 9 && x + dx >= 0 && x + dx <= 9)) {
                if (own_matrix.at(y + dy).at(x + dx) == 'S') {
                    own_matrix.at(y).at(x) = 'X';
                    return false;
                }
                else if (own_matrix.at(y + dy).at(x + dx) == 'X') {
                    bool result = get_shot(x + dx, y + dy);
                    own_matrix.at(y).at(x) = 'X';
                    return result;
                }
            }
        }
    }

    own_matrix.at(y).at(x) = 'X';
    return true;
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
            //if (own_matrix.at(std::min(y1, y2) + i).at(x1) == 'S') return false;
            if (is_ship_near(x1, std::min(y1, y2) + i)) return false;
            i++;
        }
    }
    else if (y1 == y2) {
        int i = 0;
        while (std::min(x1, x2) + i < std::max(x1, x2)) {
            //if (own_matrix.at(y1).at(std::min(x1, x2) + i) == 'S') return false;
            if (is_ship_near(std::min(x1, x2) + i, y1)) return false;
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

bool IPlayer::is_ship_near(int x, int y) {
    if (x > 0) {
        if (y > 0 && own_matrix.at(y - 1).at(x - 1) == 'S') return true;
        if (y < 9 && own_matrix.at(y + 1).at(x - 1) == 'S') return true;
        if (own_matrix.at(y).at(x - 1) == 'S') return true;
    }
    if (x < 9) {
        if (y > 0 && own_matrix.at(y - 1).at(x + 1) == 'S') return true;
        if (y < 9 && own_matrix.at(y + 1).at(x + 1) == 'S') return true;
        if (own_matrix.at(y).at(x + 1) == 'S') return true;
    }
    if (y > 0 && own_matrix.at(y - 1).at(x) == 'S') return true;
    if (y < 9 && own_matrix.at(y + 1).at(x) == 'S') return true;
    if (own_matrix.at(y).at(x) == 'S') return true;

    return false;
}

// ##############################   Console player  #############################

ConsolePlayer::ConsolePlayer(IGameView* game_view_in) {
    // setting name
    std::cout << "Type player name: ";
    std::getline(std::cin, name);

    game_view = game_view_in;

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
    std::cout << std::endl << name << "'s turn!" << std::endl;

    game_view->draw_enemy_board(own_matrix, opponent_matrix);

    // getting coordinates to hit
    bool is_valid = false;
    std::pair<int, int> coordinates;
    while (!is_valid) {
        std::cout << "Fire in sector: ";
        coordinates = get_coordinates_cin();

        if (coordinates.first >= 0 && coordinates.first <= 9 && coordinates.second >= 0 && coordinates.second <= 9) is_valid = true;
        else {
            std::cout << "Invalid coordinates, sir." << std::endl;
        }
    }

    // if alreaydy hit here
    if (opponent_matrix.at(coordinates.second).at(coordinates.first) == 'X' || opponent_matrix.at(coordinates.second).at(coordinates.first) == '*') {
        return false;
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
        opponent_matrix.at(coordinates.second).at(coordinates.first) = '*';
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

    std::pair<int, int> coor1, coor2;
    std::cout << "Let's start with four-deck one" << std::endl;
    std::cout << "Enter coordinates of first end: ";
    coor1 = get_coordinates_cin();
    std::cout << "Enter coordinates of second end: ";
    coor2 = get_coordinates_cin();
    while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 4 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
        std::cout << std::endl << "Invalid coordinates." << std::endl;
        std::cout << "Arrange four-deck ship" << std::endl;
        std::cout << "Enter coordinates of first end: ";
        coor1 = get_coordinates_cin();
        std::cout << "Enter coordinates of second end: ";
        coor2 = get_coordinates_cin();
    }

    for (int i = 0; i < 2; i++) {
        std::cout << "Now set three-deck's ship" << std::endl;
        std::cout << "Enter coordinates of first end: ";
        coor1 = get_coordinates_cin();
        std::cout << "Enter coordinates of second end: ";
        coor2 = get_coordinates_cin();
        while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 3 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second)) {
            std::cout << std::endl << "Invalid coordinates." << std::endl;
            std::cout << "Arrange three-deck ship" << std::endl;
            std::cout << "Enter coordinates of first end: ";
            coor1 = get_coordinates_cin();
            std::cout << "Enter coordinates of second end: ";
            coor2 = get_coordinates_cin();
        }
    }

    for (int i = 0; i < 3; i++) {
        std::cout << "Now set two-deck's ship" << std::endl;
        std::cout << "Enter coordinates of first end: ";
        coor1 = get_coordinates_cin();
        std::cout << "Enter coordinates of second end: ";
        coor2 = get_coordinates_cin();
        while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 2 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second)) {
            std::cout << std::endl << "Invalid coordinates." << std::endl;
            std::cout << "Arrange two-deck ship" << std::endl;
            std::cout << "Enter coordinates of first end: ";
            coor1 = get_coordinates_cin();
            std::cout << "Enter coordinates of second end: ";
            coor2 = get_coordinates_cin();
        }
    }

    for (int i = 0; i < 4; i++) {
        std::cout << "Set single-deck ship with one coordinate" << std::endl;
        std::cout << "Enter coordinate: ";
        coor1 = get_coordinates_cin();
        coor2.second = coor1.second;
        coor2.first = coor1.first;
        while (!set_ship(coor1.first, coor1.second, coor2.first, coor2.second)) {
            std::cout << std::endl << "Invalid coordinates." << std::endl;
            std::cout << "Enter new coordinate: ";
            coor1 = get_coordinates_cin();
            coor2.second = coor1.second;
            coor2.first = coor1.first;
        }
    }

}

// ##############################   Random player  #############################

RandomPlayer::RandomPlayer(IGameView* game_view_in) {
    std::cout << "Type random player name: ";
    std::getline(std::cin, name);

    game_view = game_view_in;

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
        shoot_matrix.push_back(tmp_vector);
    }
}

bool RandomPlayer::make_move(IPlayer& enemy) {
    std::cout << std::endl << name << "'s turn!" << std::endl;

    // getting coordinates to hit
    bool is_valid = false;
    std::pair<int, int> coordinates = get_coordinates_rand();
    while (!is_valid && shoot_matrix.at(coordinates.second).at(coordinates.first) != '~') {
        coordinates = get_coordinates_rand();
    }

    std::cout << "Fire in sector " << coordinates.first << " " << coordinates.second << std::endl;
    shoot_matrix.at(coordinates.second).at(coordinates.first) = 'X';
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
        std::cout << "Miss" << std::endl;
    }

    return false;
}

void RandomPlayer::arrange_board() {
    std::srand(time(0));

    std::pair<int, int> coor1, coor2;
    coor1 = get_coordinates_rand();
    coor2 = get_coordinates_rand();
    if (rand() % 2 == 1) {
        coor2.second = coor1.second;
    }
    else {
        coor2.first = coor1.first;
    }
    while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 4 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
        coor1 = get_coordinates_rand();
        coor2 = get_coordinates_rand();
        if (rand() % 2 == 1) {
            coor2.second = coor1.second;
            coor2.first = coor1.first + 3;
        }
        else {
            coor2.first = coor1.first;
            coor2.second = coor1.second + 3;
        }
    }

    for (int i = 0; i < 2; i++) {
        while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 3 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
            coor1 = get_coordinates_rand();
            coor2 = get_coordinates_rand();
            if (rand() % 2 == 1) {
                coor2.second = coor1.second;
                coor2.first = coor1.first + 2;
            }
            else {
                coor2.first = coor1.first;
                coor2.second = coor1.second + 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 2 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
            coor1 = get_coordinates_rand();
            coor2 = get_coordinates_rand();
            if (rand() % 2 == 1) {
                coor2.second = coor1.second;
                coor2.first = coor1.first + 1;
            }
            else {
                coor2.first = coor1.first;
                coor2.second = coor1.second + 1;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        coor1 = get_coordinates_rand();
        coor2.second = coor1.second;
        coor2.first = coor1.first;
        while (!set_ship(coor1.first, coor1.second, coor2.first, coor2.second)) {
            coor1 = get_coordinates_rand();
            coor2.second = coor1.second;
            coor2.first = coor1.first;
        }
    }
}

// ##############################   Optimal player  ############################

OptimalPlayer::OptimalPlayer(IGameView* game_view_in) {
    std::cout << "Type optimal player name: ";
    std::getline(std::cin, name);

    game_view = game_view_in;

    last_hit = {-1, -1};
    orientation = 'n';
    made_one_side = false;

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
        shoot_matrix.push_back(tmp_vector);
    }
}

bool OptimalPlayer::make_move(IPlayer& enemy) {
    std::cout << std::endl << name << "'s turn!" << std::endl;

    // getting coordinates to hit
    std::pair<int, int> coordinates = get_coordinates_rand();
    while (shoot_matrix.at(coordinates.second).at(coordinates.first) != '~') {
        coordinates = get_coordinates_rand();
    }

    int x = coordinates.first;
    int y = coordinates.second;

    if (last_hit.first != -1) {
        if (orientation == 'n') {
            if (last_hit.first - 1 >= 0 && shoot_matrix.at(last_hit.second).at(last_hit.first - 1) == '~') {
                coordinates.first = last_hit.first - 1;
                coordinates.second = last_hit.second;
                if (enemy.is_there(coordinates.first - 1, coordinates.second)) {
                    orientation = 'h';
                }
            }
            else if (last_hit.first + 1 <= 9 && shoot_matrix.at(last_hit.second).at(last_hit.first + 1) == '~') {
                coordinates.first = last_hit.first + 1;
                coordinates.second = last_hit.second;
                if (enemy.is_there(coordinates.first + 1, coordinates.second)) {
                    orientation = 'h';
                }
            }
            else if (last_hit.second - 1 >= 0 && shoot_matrix.at(last_hit.second - 1).at(last_hit.first) == '~') {
                coordinates.first = last_hit.first;
                coordinates.second = last_hit.second - 1;
                if (enemy.is_there(coordinates.first, coordinates.second - 1)) {
                    orientation = 'v';
                }
            }
            else if (last_hit.second + 1 <= 9 && shoot_matrix.at(last_hit.second + 1).at(last_hit.first) == '~') {
                coordinates.first = last_hit.first;
                coordinates.second = last_hit.second + 1;
                if (enemy.is_there(coordinates.first, coordinates.second + 1)) {
                    orientation = 'v';
                }
            }
        }
        if (orientation = 'h') {
            if (last_hit.first - 1 >= 0 && shoot_matrix.at(last_hit.second).at(last_hit.first - 1) == '~' && !made_one_side) {
                coordinates.first = last_hit.first - 1;
                coordinates.second = last_hit.second;
                if (!enemy.is_there(coordinates.first - 1, coordinates.second)) {
                    made_one_side = true;
                }
            }
            else if (last_hit.first + 1 <= 9 && shoot_matrix.at(last_hit.second).at(last_hit.first + 1) == '~') {
                coordinates.first = last_hit.first + 1;
                coordinates.second = last_hit.second;
                if (!enemy.is_there(coordinates.first + 1, coordinates.second)) {
                    last_hit = {-1, -1};
                    orientation = 'n';
                    made_one_side = false;
                }
            }
        }
        if (orientation = 'v') {
            if (last_hit.second - 1 >= 0 && shoot_matrix.at(last_hit.second - 1).at(last_hit.first) == '~' && !made_one_side) {
                coordinates.first = last_hit.first;
                coordinates.second = last_hit.second - 1;
                if (!enemy.is_there(coordinates.first, coordinates.second - 1)) {
                    made_one_side = true;
                }
            }
            else if (last_hit.second + 1 <= 9 && shoot_matrix.at(last_hit.second + 1).at(last_hit.first) == '~') {
                coordinates.first = last_hit.first;
                coordinates.second = last_hit.second + 1;
                if (!enemy.is_there(coordinates.first, coordinates.second + 1)) {
                    last_hit = {-1, -1};
                    orientation = 'n';
                    made_one_side = false;
                }
            }
        }
    }

    std::cout << "Fire in sector " << coordinates.first << " " << coordinates.second << std::endl;
    shoot_matrix.at(coordinates.second).at(coordinates.first) = 'X';
    // if hit
    if (enemy.is_there(coordinates.first, coordinates.second)) {
        last_hit = coordinates;
        opponent_matrix.at(coordinates.second).at(coordinates.first) = 'X';
        if (enemy.get_shot(coordinates.first, coordinates.second)) {
            std::cout << "Ship is destroyed!" << std::endl;
            last_hit = {-1, -1};
            orientation = 'n';
            made_one_side = false;
        }
        else {
            std::cout << "Hit!" << std::endl;
            /*for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if ((dx == 0 && dy == 0) || (dx != 0 && dy != 0)) continue;
                    if ((y + dy >= 0 && y + dy <= 9 && x + dx >= 0 && x + dx <= 9)) {
                        
                    }
                }
            }*/
        }
        return true;
    }
    // if missed
    else {
        std::cout << "Miss" << std::endl;
    }

    return false;
}

void OptimalPlayer::arrange_board() {
    std::srand(time(0));

    std::pair<int, int> coor1, coor2;
    coor1 = get_coordinates_rand();
    coor2 = get_coordinates_rand();
    if (rand() % 2 == 1) {
        coor2.second = coor1.second;
    }
    else {
        coor2.first = coor1.first;
    }
    while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 4 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
        coor1 = get_coordinates_rand();
        coor2 = get_coordinates_rand();
        if (rand() % 2 == 1) {
            coor2.second = coor1.second;
            coor2.first = coor1.first + 3;
        }
        else {
            coor2.first = coor1.first;
            coor2.second = coor1.second + 3;
        }
    }

    for (int i = 0; i < 2; i++) {
        while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 3 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
            coor1 = get_coordinates_rand();
            coor2 = get_coordinates_rand();
            if (rand() % 2 == 1) {
                coor2.second = coor1.second;
                coor2.first = coor1.first + 2;
            }
            else {
                coor2.first = coor1.first;
                coor2.second = coor1.second + 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        while (ship_len(coor1.first, coor1.second, coor2.first, coor2.second) != 2 || !set_ship(coor1.first, coor1.second, coor2.first, coor2.second) || coor1.first == -1 || coor2.first == -1) {
            coor1 = get_coordinates_rand();
            coor2 = get_coordinates_rand();
            if (rand() % 2 == 1) {
                coor2.second = coor1.second;
                coor2.first = coor1.first + 1;
            }
            else {
                coor2.first = coor1.first;
                coor2.second = coor1.second + 1;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        coor1 = get_coordinates_rand();
        coor2.second = coor1.second;
        coor2.first = coor1.first;
        while (!set_ship(coor1.first, coor1.second, coor2.first, coor2.second)) {
            coor1 = get_coordinates_rand();
            coor2.second = coor1.second;
            coor2.first = coor1.first;
        }
    }
}

// ################################   Game View  ##############################

ConsoleView::ConsoleView() {};

void ConsoleView::draw_enemy_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy) {
    std::cout << std::endl;
    std::cout << "  1 2 3 4 5 6 7 8 9 10" << std::endl;
    for (int y = 0; y < BOARD_SIZE; y++) {
        if (y < BOARD_SIZE - 1) {
            std::cout << y + 1 << " ";
        }
        else {
            std::cout << y + 1;
        }
        for (int x = 0; x < BOARD_SIZE; x++) {
            std::cout << matrix_enemy.at(y).at(x) << " ";
        }
        std::cout << std::endl;
    }
}

void ConsoleView::draw_own_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            std::cout << matrix_own.at(y).at(x) << " ";
        }
        std::cout << std::endl;
    }
}
