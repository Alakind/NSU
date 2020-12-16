#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <exception>

static int BOARD_SIZE = 10;

bool is_number(const std::string s);

class Game {
    private:
        int p1_score;
        int p2_score;
        int number_of_rounds;
    public:
        Game();

        bool is_over();
};

class IPlayer {
    public:
        int health;     // max health = 20 (all ships)
        std::vector<std::vector<char>> own_matrix;
        std::vector<std::vector<char>> opponent_matrix;
        std::string name;

        int get_health() { return health; };
        bool is_dead();
        bool is_there(int x, int y);
        bool get_shot(int x, int y);
        bool is_killed(std::vector<std::vector<char>> matrix, std::pair<int, int> coordinates);
        virtual bool make_move(IPlayer& enemy) = 0;
        virtual void arrange_board() = 0;
        bool set_ship(int x1, int y1, int x2, int y2); // returns false if ship cannot be arranged, true otherwise
        int ship_len(int x1, int y1, int x2, int y2);
        void print_matrix();
};

class ConsolePlayer : public IPlayer {
    public:
        ConsolePlayer();

        virtual bool make_move(IPlayer& enemy);
        virtual void arrange_board();
        
};

class RandomPlayer : public IPlayer {
    public:
        RandomPlayer();

        virtual bool make_move();
        virtual void arrange_board();
};

class OptimalPlayer : public IPlayer {
    public:
        OptimalPlayer();

        virtual bool make_move();
        virtual void arrange_board();
};

class IGameView {
    public:
        virtual void draw_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy);
};

class ConsoleView : IGameView {
    public:
        virtual void draw_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy);
};
