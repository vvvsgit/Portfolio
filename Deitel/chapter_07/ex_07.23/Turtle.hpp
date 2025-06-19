const int SIZE = 20;
enum Direction{NORTH, EAST, SOUTH, WEST};
enum Pen{UP, DOWN, ERASE};

class Turtle
{
public:
    Turtle();
    void setFloor(bool);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    void setPen(Pen);
    Pen getPen();
    void setDirection(Direction);
    Direction getDirection();
    void runTurtle();
    int printCommands();
    void chooseCommand(int);
    void turnRight();
    void turnLeft();
    void moveForward();
    int getSpaces();
    bool checkMoveValidity(int);
    void showCordinates();
    void showDirection();
    void printFloor();
private:
    bool floor_[SIZE][SIZE];
    int x_;
    int y_;
    Direction direction_;
    Pen pen_;
};

