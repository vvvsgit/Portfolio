#include "headers/TicTacToe.hpp"
#include "headers/Player.hpp"
#include "headers/Board.hpp"

int
main()
{
    Player player1("Ezio", 'X');
    Player player2("Arantes", 'O');

    std::vector<Player*> players;
    players.push_back(&player1);
    players.push_back(&player2);
    Board board;
    
    TicTacToe game(players, board);
    game.play();

    return 0;
}

