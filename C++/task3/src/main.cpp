#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <exception>
#include "battleship.h"
#include "optionparser.h"

struct Arg: public option::Arg {
    static void printError(const char* msg1, const option::Option& opt, const char* msg2) {
        fprintf(stderr, "ERROR: %s", msg1);
        fwrite(opt.name, opt.namelen, 1, stderr);
        fprintf(stderr, "%s", msg2);
    }
    static option::ArgStatus Unknown(const option::Option& option, bool msg) {
    if (msg) printError("Unknown option '", option, "'\n");
        return option::ARG_ILLEGAL;
    }
    static option::ArgStatus Required(const option::Option& option, bool msg) {
        if (option.arg != 0)
            return option::ARG_OK;
        if (msg) printError("Option '", option, "' requires an argument\n");
            return option::ARG_ILLEGAL;
    }
    static option::ArgStatus NonEmpty(const option::Option& option, bool msg) {
        if (option.arg != 0 && option.arg[0] != 0)
            return option::ARG_OK;
        if (msg) printError("Option '", option, "' requires a non-empty argument\n");
        return option::ARG_ILLEGAL;
    }
    static option::ArgStatus Numeric(const option::Option& option, bool msg) {
        char* endptr = 0;
        if (option.arg != 0 && strtol(option.arg, &endptr, 10)){};
        if (endptr != option.arg && *endptr == 0)
            return option::ARG_OK;
        if (msg) printError("Option '", option, "' requires a numeric argument\n");
            return option::ARG_ILLEGAL;
    }
};

enum  optionIndex { PLAYER1, PLAYER2, HELP };
const option::Descriptor usage[] = {
    {HELP, 0,"h", "help", Arg::None, "  --help  \tPrint usage and exit." },
    {PLAYER1, 0,"f","first", Arg::NonEmpty, "  --first, -f  \tMake first player." },
    {PLAYER2, 0,"s","second", Arg::NonEmpty, "  --second, -s  \tMake second player." },
};

IPlayer* make_player(PlayerType player_type, ConsoleView* game_view) {
    switch (player_type) {
    case PlayerType::type_optimal: {
        OptimalPlayer* player_op = new OptimalPlayer (game_view);
        return player_op;
    }
    case PlayerType::type_console: {
        ConsolePlayer* player_con = new ConsolePlayer (game_view);
        return player_con;
    }
    default: {    // default - random player
        RandomPlayer* player_ran = new RandomPlayer (game_view);
        return player_ran;
    }
    }
}

int main(int argc, char* argv[]) {
    argc -= (argc > 0); argv += (argc > 0); // skip program name argv[0] if present
    option::Stats stats(usage, argc, argv);
    std::vector<option::Option> options(10);
    std::vector<option::Option> buffer(stats.buffer_max);
    option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);
    if (parse.error()) return 1;

    PlayerType player1_type;
    PlayerType player2_type;

    if (sizeof(options[PLAYER1].arg) > 0) { 
        switch (options[PLAYER1].arg[0]) {
        case 'c':
            player1_type = PlayerType::type_console;
            break;
        case 'o':
            player1_type = PlayerType::type_optimal;
            break;
        case 'r':
            player1_type = PlayerType::type_random;
            break;
        default:
            std::cout << "invalid input" << std::endl;
            return 0;
        }
    }
    else {
        player1_type = PlayerType::type_random;
    }

    if (sizeof(options[PLAYER2].arg) > 0) { 
        switch (options[PLAYER2].arg[0]) {
        case 'c':
            player2_type = PlayerType::type_console;
            break;
        case 'o':
            player2_type = PlayerType::type_optimal;
            break;
        case 'r':
            player2_type = PlayerType::type_random;
            break;
        default:
            std::cout << "invalid input" << std::endl;
            return 0;
        }
    }
    else {
        player2_type = PlayerType::type_random;
    }


    ConsoleView game_view;

    IPlayer* player1 = make_player(player1_type, &game_view);
    IPlayer* player2 = make_player(player2_type, &game_view);

    player1->arrange_board();
    player2->arrange_board();

    Game game(player1, player2);
    game.play_game();


    return 0;
}
