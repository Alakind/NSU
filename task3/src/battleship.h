#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <exception>

class IPlayer {
    public:
        int health;     // max health = 20 (all ships)
        std::vector<std::vector<char>> own_matrix;
        std::vector<std::vector<char>> opponent_matrix;
        std::string name;
        int get_health() { return health; };
        bool is_dead();
        bool is_there(int x, int y);
        void make_move();
};

class ConsolePlayer : public IPlayer {
    public:
        explicit ConsolePlayer();
};

class RandomPlayer : public IPlayer {
    public:
        explicit RandomPlayer();
};

class OptimalPlayer : public IPlayer {
    public:
        explicit OptimalPlayer();
};

class IGameView {
    public:
        void draw_board(std::vector<std::vector<char>> matrix_own, std::vector<std::vector<char>> matrix_enemy);
};

class ConsoleView : IGameView {
    
};
