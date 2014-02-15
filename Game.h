//Header
#ifndef Game_h
#define Game_h

#include <Arduino.h>

class Game
{
  public:
  Game(int row, int column);
  boolean tie();
  boolean checkWinO();
  boolean checkWinX();
  void printboard();
  boolean spotvacant(int row, int column);
  void blockWin();
  int getRow();
  int getColumn();

  private:
  int _row;
  int _column;
  char gameboard[3][3];
};

#endif
