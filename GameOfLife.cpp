#include "GameOfLife.h"
#include <fstream>

Game::Game(){
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      gameBoard[i][j] = ' ';
    }
  }
}

void Game::introduction(){
  int option;
  cout << "This is the Game of Life" << endl;
  cout << "Choose a number: " << endl;
  cout << "Random configuration (0) | Specify a flat-file organization (1)" << endl;
  cin >> option;
    if(option == 0) {
      randomBoard();
    }
    else if (option == 1) {
      fileBoard();
    }
    else {
      cout << "Invalid input." << endl;
    }
}

void Game::printCurrentBoard(int w, int h){
  cout << gameBoard[w][h];
}

void Game::printBoard(){
  for (int i = 0; i < h; i++){
    for (int j = 0; j< w; j++){
      if ((gameBoard[i][j]) == true) {
        cout << "X ";
      }
      else {
        cout << "- ";
      }
    }
    cout << endl;
  }
}

int Game::countNeighbor(int w, int h){
  int count = 0;
  for(int i = w-1; i = w+1; i++)
  {
      for(int j = h-1; j <= h+1; j++)
      {
      count += gameBoard[i][j]; //if neighbour alive
      }
  }
  count -= gameBoard[w][h]; //not neighbor of itself
  return count;
}


void Game::randomBoard(){
srand((unsigned int)time(NULL));
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      if ((rand() % 2) != 0){
        gameBoard[i][j] = true;
      }
      else {
        gameBoard[i][j] = false;
      }
    }
  }
  printBoard();
}

bool Game::fileBoard(){
  ifstream myfile;
  string userfile;
  cout << "Which file do you want to open?" << endl;
  cin >> userfile;
  myfile.open (userfile);
  if (!myfile){
    return true;
  }
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      myfile >> gameBoard[i][j];
    }
  }
printBoard();
myfile.close();
return false;
}

int Game::getIterations(unsigned int nIterations){
  unsigned int iterations;
    cout << "How many iterations of the game?" << endl;
    cin >> iterations;
    return iterations;
}

void Game::runGame(int iterations){
  int w;
  int h;
  for (int i = 0; i < iterations; ++i){
    printCurrentBoard(w,h);
    countNeighbor(w,h);
    printCurrentBoard(w,h);
  }
}
