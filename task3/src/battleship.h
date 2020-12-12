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

class IPlayer {
    public:
        int health;     // max health = 20 (all ships)
        std::vector<std::vector<char>> own_matrix;
        std::vector<std::vector<char>> opponent_matrix;
        std::string name;

        int get_health() { return health; };
        bool is_dead();
        bool is_there(int x, int y);
        virtual void make_move() = 0;
};

class ConsolePlayer : public IPlayer {
    private:
        std::pair<int, int> get_coordinates(std::string string);
    public:
        ConsolePlayer();

        virtual void make_move();
};

class RandomPlayer : public IPlayer {
    public:
        RandomPlayer();

        virtual void make_move();
};

class OptimalPlayer : public IPlayer {
    public:
        OptimalPlayer();

        virtual void make_move();
};

class IGameView {
    public:
        void draw_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy);
};

class ConsoleView : IGameView {
    
};
