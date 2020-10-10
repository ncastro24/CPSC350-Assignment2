#include "GameOfLife.h"

int main(int argc, char** argv) {
  int generations;
  bool play = true;
  char u;
  while (play) {
    Game *game = new Game();
    game->introduction();
    game->runGame(generations);
    cout << "Do you want to continue? (y/n): ";
    cin >> u;
    if (tolower(u) == 'n') {
      cout << "Program terminated." << endl;
      play = false;
    }
  }
  return 0;
}
