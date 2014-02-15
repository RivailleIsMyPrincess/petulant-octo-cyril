//Some code taken from previous Java code written by me in 2011
//Version 3 of "MyProject"
//Supposed to play Tic Tac Toe
//Written by Lizzy Wu on February 13, 2014

#include "Game.h"
#include <Servo.h>

Servo base, shoulder, elbow, wrist, gripper;
char gameboard[3][3] =
{
  {'~', '~', '~'},
  {'~', '~', '~'},
  {'~', '~', '~'}
};
int column;
int row;
boolean vacancy = false;
int moveBase[] = {100, 150, 200}; // by column
int moveElbow[] = {0, 50, 100}; //by row
int moveWrist[]= {100, 50, 0}; // by row

//robot plays as O
//human player plays as X

Game::Game game(row, column);

void setup()
{
  base.attach(2);
  shoulder.attach(3);
  elbow.attach(4);
  wrist.attach(10);
  gripper.attach(11);
  
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  //initialize
  for(int i = 0; i<3; i++)
  {
    for(int a = 0; a<3; a++)
    {
      gameboard[i][a] = '~';
    }
  }
  
  game.printboard();
  
  Serial.println("Write an X or O on the space you would like to occupy and leave the stamp of the other piece for me. I'll tell you if I can't find it.");
  delay(1000);

  while(game.checkWinX() == false || game.checkWinO() == false || game.tie() == false)
  {
    //main code
    
    // if X goes first
    
    //make sure human player isn't trying to take a taken spot
    while (vacancy  == false)
    {
      Serial.println("Which row would you like?");
      //place spot
      while (!Serial.available())
      {}
        row = Serial.read();
        row --;
      
      Serial.println("Which column would you like?");
      
      while(!Serial.available())
      {}
      
      column = Serial.read();
      column --;
      
      vacancy = game.spotvacant(row, column);
      
      if (gameboard[row][column] != '~')
      {
        Serial.println("Sorry, I really can't let you do that. Please try again");
      }
      else
      {
        gameboard[row][column] == 'X';
        vacancy = true;
      }
    }
      
  vacancy = false; //set as false for next main loop
  game.printboard();
  
  game.blockWin();
  row = game.getRow();
  column = game.getColumn();
  
  //needs to retrieve stamp
  //would use sensor here to see whether or not the stamp has been gripped and ask for help if can't find it
  //needs to put ink on stamp
  
  base.write(moveBase[column]);
  elbow.write(moveElbow[row]);
  wrist.write(moveWrist[row]);

  //still needs lifting and lowering motion
  
  game.printboard();
  
  }
}

void loop()
{
  //eh
}
