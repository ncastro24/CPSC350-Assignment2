#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Game{
  public:
    Game();
    Game(int, int);
    ~Game();
    void introduction(); //asks for user input and introduces the game
    void printBoard(); //print a board
    void randomBoard(); //create random board
    bool fileBoard(); //create board from file
    void printCurrentBoard(int w, int h);
    int countNeighbor(int w, int h);
    int getIterations(unsigned int nIterations); //how many iterations of a game
    void runGame(int); //run a game

  private:
    static const unsigned int h = 10; //height of cell space
    static const unsigned int w = 10; //width of cell space
    char gameBoard[h][w];
};
