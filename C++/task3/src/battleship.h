#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <exception>
#include <cstdlib>
#include <ctime>
static int BOARD_SIZE = 10;

bool is_number(const std::string s);

std::pair<int, int> get_coordinates_cin();
std::pair<int, int> get_coordinates_rand();

enum PlayerType {
    type_random,    // random - 0
    type_optimal,   // optimal - 1
    type_console    // console - 2
};

class IGameView;

class IPlayer {
    public:

        //int health;     // max health = 20 (all ships)
        std::vector<std::vector<char>> own_matrix;
        std::vector<std::vector<char>> opponent_matrix;
        std::string name;

        //IGameView* game_view;

        //int get_health() { return health; };
        //bool is_dead(); // checks if player is defeated
        bool is_there(int x, int y); // checks if there a ship at own_matrix
        bool get_shot(int x, int y); // get damage on own_matrix, returns true if ship is destroyed
        bool is_killed(std::vector<std::vector<char>> matrix, std::pair<int, int> coordinates); // checks if ship is destroyed
        virtual bool make_move(IPlayer& enemy) = 0; // returns true if has additional move
        virtual void arrange_board() = 0; // set all ships
        bool set_ship(int x1, int y1, int x2, int y2); // returns false if ship cannot be arranged, true otherwise
        int ship_len(int x1, int y1, int x2, int y2);
        void print_matrix();
        bool is_ship_near(int x, int y); // returns true if this sector collides with ship
};

class ConsolePlayer : public IPlayer {
    public:
        ConsolePlayer(IGameView* game_view_in);

        IGameView* game_view;
        //int enemy_health;     // max health = 20 (all ships)

        //bool is_dead(); // checks if player is defeated
        //int get_health() { return enemy_health; };
        virtual bool make_move(IPlayer& enemy);
        virtual void arrange_board();
        
};

class RandomPlayer : public IPlayer {
    public:
        RandomPlayer(IGameView* game_view_in);

        std::vector<std::vector<char>> shoot_matrix;
        IGameView* game_view;
        //int enemy_health;     // max health = 20 (all ships)

        //bool is_dead(); // checks if player is defeated
        //int get_health() { return enemy_health; };
        virtual bool make_move(IPlayer& enemy);
        virtual void arrange_board();
};

class OptimalPlayer : public IPlayer {
    public:
        OptimalPlayer(IGameView* game_view_in);

        IGameView* game_view;
        //int enemy_health;     // max health = 20 (all ships)
        std::pair<int, int> last_hit;
        char orientation;
        bool made_one_side;

        std::vector<std::vector<char>> shoot_matrix;

        //bool is_dead(); // checks if player is defeated
        //int get_health() { return enemy_health; };
        virtual bool make_move(IPlayer& enemy);
        virtual void arrange_board();
};

class IGameView {
    public:
        virtual void draw_enemy_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy) = 0;
        virtual void draw_own_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy) = 0;
};

class ConsoleView : public IGameView {
    public:
        ConsoleView();

        virtual void draw_enemy_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy);
        virtual void draw_own_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy);
};

class Game {
    private:
        int p1_score;
        int p2_score;
        int number_of_rounds;
    public:
        Game(IPlayer* player1_in, IPlayer* player2_in);

        IPlayer* player1;
        IPlayer* player2;
        bool is_over();
        void play_game();
        bool play_round();  // return true if first player wins
};