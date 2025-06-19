#include <iostream>
#include <cassert>

const int SIZE = 13;
enum Direction{EAST, SOUTH, WEST, NORTH};
Direction DIRECTION = EAST;

void printMaze(char [][SIZE]);
void waitForIt();
void mazeTraverse(char [][SIZE], int, int);
void doStep(char [][SIZE], int *, int *);
bool isRightOpen(char [][SIZE], int, int);
bool isForwardOpen(char [][SIZE], int, int);
bool isLeftOpen(char [][SIZE], int, int);
bool isBackwardOpen(char [][SIZE], int, int);
void turnRight();
void turnLeft();

int
main()
{
    std::cout << std::endl;
    int startRow = 2;
    int startColumn = 0;
    char maze[SIZE - 1][SIZE] = {{"############"},
                                 {"#...#......#"},
                                 {"..#.#.####.#"},
                                 {"###.#....#.#"},
                                 {"#....###.#.."},
                                 {"####.#.#.#.#"},
                                 {"#..#.#.#.#.#"},
                                 {"##.#.#.#.#.#"},
                                 {"#........#.#"},
                                 {"######.###.#"},
                                 {"#......#...#"},
                                 {"############"}};
    mazeTraverse(maze, startRow, startColumn);

    std::cout << std::endl;
    return 0;
}

void
printMaze(char maze[][SIZE])
{
    for (int i = 0; i < 30; ++i) {
        std::cout << std::endl;
    }
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << ' ' << maze[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    waitForIt();
}

void
waitForIt()
{
    for (int i = 0; i < 150000000; ++i);
}


void
mazeTraverse(char maze[][SIZE], int row, int column)
{
    static bool isNotFirst = false;
    printMaze(maze);
    maze[row][column] = (maze[row][column] == '.' ? 'x' : 'X');
    if (isNotFirst && (row == 0 || column == 0 || row == SIZE - 2 || column == SIZE - 2)) {
        printMaze(maze);
        return;
    }
    if (isRightOpen(maze, row, column)) {
        isNotFirst = true;
        turnRight();
        doStep(maze, &row, &column);
        mazeTraverse(maze, row, column);
        return;
    }
    if (isForwardOpen(maze, row, column)) {
        isNotFirst = true;
        doStep(maze, &row, &column);
        mazeTraverse(maze, row, column);
        return;
    }
    if (isLeftOpen(maze, row, column)) {
        isNotFirst = true;
        turnLeft();
        doStep(maze, &row, &column);
        mazeTraverse(maze, row, column);
        return;
    }
    if (isBackwardOpen(maze, row, column)) {
        isNotFirst = true;
        turnRight();
        turnRight();
        doStep(maze, &row, &column);
        mazeTraverse(maze, row, column);
        return;
    }
}

void
doStep(char maze[][SIZE], int *ptrRow, int *ptrColumn)
{
    switch (DIRECTION) {
    case EAST:  ++*ptrColumn; break;
    case SOUTH: ++*ptrRow;    break;
    case WEST:  --*ptrColumn; break;
    case NORTH: --*ptrRow;    break;
    default: assert(0);       break;
    }
}

bool
isRightOpen(char maze[][SIZE], int row, int column)
{
    if (DIRECTION == EAST && maze[row + 1][column] != '#') {
        return true;
    }
    if (DIRECTION == SOUTH && maze[row][column - 1] != '#') {
        return true;
    }
    if (DIRECTION == WEST && maze[row - 1][column] != '#') {
        return true;
    }
    if (DIRECTION == NORTH && maze[row][column + 1] != '#') {
        return true;
    }
    return false;
}

bool
isForwardOpen(char maze[][SIZE], int row, int column)
{
    if (DIRECTION == EAST && maze[row][column + 1] != '#') {
        return true;
    }
    if (DIRECTION == SOUTH && maze[row + 1][column] != '#') {
        return true;
    }
    if (DIRECTION == WEST && maze[row][column - 1] != '#') {
        return true;
    }
    if (DIRECTION == NORTH && maze[row - 1][column] != '#') {
        return true;
    }
    return false;
}

bool
isLeftOpen(char maze[][SIZE], int row, int column)
{
    if (DIRECTION == EAST && maze[row - 1][column] != '#') {
        return true;
    }
    if (DIRECTION == SOUTH && maze[row][column + 1] != '#') {
        return true;
    }
    if (DIRECTION == WEST && maze[row + 1][column] != '#') {
        return true;
    }
    if (DIRECTION == NORTH && maze[row][column - 1] != '#') {
        return true;
    }
    return false;
}

bool
isBackwardOpen(char maze[][SIZE], int row, int column)
{
    if (DIRECTION == EAST && maze[row][column - 1] != '#') {
        return true;
    }
    if (DIRECTION == SOUTH && maze[row - 1][column] != '#') {
        return true;
    }
    if (DIRECTION == WEST && maze[row][column + 1] != '#') {
        return true;
    }
    if (DIRECTION == NORTH && maze[row + 1][column] != '#') {
        return true;
    }
    return false;
}

void
turnRight()
{
    switch (DIRECTION) {
    case EAST:  DIRECTION = SOUTH; break;
    case SOUTH: DIRECTION = WEST;  break;
    case WEST:  DIRECTION = NORTH; break;
    case NORTH: DIRECTION = EAST;  break;
    default: assert(0);            break;
    }
}

void
turnLeft()
{
    switch (DIRECTION) {
    case EAST:  DIRECTION = NORTH; break;
    case NORTH: DIRECTION = WEST;  break;
    case WEST:  DIRECTION = SOUTH; break;
    case SOUTH: DIRECTION = EAST;  break;
    default: assert(0);            break;
    }
}

