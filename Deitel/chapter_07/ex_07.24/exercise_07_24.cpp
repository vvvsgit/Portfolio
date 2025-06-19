#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

const int BOARD_SIZE = 8;
const int MOVE_COUNT = 8;
const int HORIZONTAL[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int VERTICAL[MOVE_COUNT]   = {-1, -2, -2, -1, 1, 2, 2, 1};

bool isInBoard(const int row, const int column);
void decreasingAvailableMoves(int heuristic[][BOARD_SIZE], const int row, const int column);
void increasingAvailableMoves(int heuristic[][BOARD_SIZE], const int row, const int column);
void takeMove(int heuristic[][BOARD_SIZE], int& row, int& column);
void printChessBoard(const int chessBoard[][BOARD_SIZE]);

int
main()
{
    if (::isatty(STDIN_FILENO)) {
        std::srand(std::time(0));
    }
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int heuristic[BOARD_SIZE][BOARD_SIZE] = {
        {2, 3, 4, 4, 4, 4, 3, 2},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {2, 3, 4, 4, 4, 4, 3, 2}
    };
    int currentRow = std::rand() % MOVE_COUNT, currentColumn = std::rand() % MOVE_COUNT;
    for (int myMove = 1; myMove <= BOARD_SIZE * BOARD_SIZE; ++myMove) {
        board[currentRow][currentColumn] = myMove;
        heuristic[currentRow][currentColumn] = 0;
        int previousRow = currentRow, previousColumn = currentColumn;
        takeMove(heuristic, currentRow, currentColumn);
        decreasingAvailableMoves(heuristic, previousRow, previousColumn);
    }
    printChessBoard(board);
    return 0;
}

bool
isInBoard(const int row, const int column)
{
    return !(row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE);
}

void
decreasingAvailableMoves(int heuristic[][BOARD_SIZE], const int row, const int column)
{
    for (int moveNumber = 0; moveNumber < MOVE_COUNT; ++moveNumber) {
        const int nextRow = row + VERTICAL[moveNumber];
        const int nextColumn = column + HORIZONTAL[moveNumber];
        if (isInBoard(nextRow, nextColumn) && heuristic[nextRow][nextColumn] > 0) {
            --heuristic[nextRow][nextColumn];
        }
    }
}

void
increasingAvailableMoves(int heuristic[][BOARD_SIZE], const int row, const int column)
{
    for (int moveNumber = 0; moveNumber < MOVE_COUNT; ++moveNumber) {
        const int nextRow = row + VERTICAL[moveNumber];
        const int nextColumn = column + HORIZONTAL[moveNumber];
        if (isInBoard(nextRow, nextColumn) && heuristic[nextRow][nextColumn] > 0) {
            ++heuristic[nextRow][nextColumn];
        }
    }
}

void
takeMove(int heuristic[][BOARD_SIZE], int& row, int& column)
{
    int smallest = MOVE_COUNT + 12, newRow = row, newColumn = column;
    for (int moveNumber = 0; moveNumber < MOVE_COUNT; ++moveNumber) {
        const int nextRow = row + VERTICAL[moveNumber];
        const int nextColumn = column + HORIZONTAL[moveNumber];
        if (isInBoard(nextRow, nextColumn) && heuristic[nextRow][nextColumn] > 0 && smallest >= heuristic[nextRow][nextColumn]) {
            if (smallest == heuristic[nextRow][nextColumn]) {
                int row1 = newRow, column1 = newColumn;
                heuristic[row1][column1] *= -1;
                decreasingAvailableMoves(heuristic, row1, column1);
                const int row1_1 = row1, column1_1 = column1;
                takeMove(heuristic, row1, column1);
                const int smallest1 = heuristic[row1][column1];
                increasingAvailableMoves(heuristic, row1_1, column1_1);
                heuristic[row1_1][column1_1] *= -1;

                int row2 = nextRow, column2 = nextColumn;
                heuristic[row2][column2] *= -1;
                decreasingAvailableMoves(heuristic, row2, column2);
                const int row2_1 = row2, column2_1 = column2;
                takeMove(heuristic, row2, column2);
                const int smallest2 = heuristic[row2][column2];
                increasingAvailableMoves(heuristic, row2_1, column2_1);
                heuristic[row2_1][column2_1] *= -1;
                if (smallest1 <= smallest2) { break; }
            }
            smallest = heuristic[nextRow][nextColumn];
            newRow = nextRow;
            newColumn = nextColumn;
        }
    }
    row = newRow;
    column = newColumn;
}

void
printChessBoard(const int chessBoard[][BOARD_SIZE])
{
    std::cout << std::endl;
    std::cout << "       ♞   A   B   C   D   E   F   G   H   ♘" << std::endl;
    std::cout << "         ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓" << std::endl;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        std::cout << "       " << -(row - BOARD_SIZE) << " ┃";
        for (int column = 0; column < BOARD_SIZE; ++column) {
            std::cout << std::setw(3) << chessBoard[row][column] << "┃";
        }
        std::cout << " " << -(row - BOARD_SIZE) << std::endl;
        if (row == 7) {break; }
        std::cout << "         ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫" << std::endl;
    }
    std::cout << "         ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛" << std::endl;
    std::cout << "       ♘   A   B   C   D   E   F   G   H   ♞" << std::endl;
    std::cout << std::endl;
}

