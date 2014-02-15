#include "Arduino.h"
#include "Game.h"


Game::Game(int row, int column)
{
  _row = row;
  _column = column;
}

boolean Game::checkWinX()
{
  //loop checks if x has won for rows
  for(int i = 0; i<3; i++)
  {
    if(gameboard[i][0] == 'X' && gameboard[i][1] == 'X' && gameboard[i][2] == 'X')
    return true;      
  }     
  //loop checks if x has won for columns
  for(int i = 0; i<3; i++)
  {
    if(gameboard[0][i] == 'X' && gameboard[1][i] == 'X' && gameboard[2][i] == 'X')
    return true;      
  }

// these check if x has won in diagonals  
  if(gameboard[0][0] == 'X' && gameboard[1][1] == 'X' && gameboard[2][2] == 'X')
  {
    return true;
  }    
  if(gameboard[0][2] == 'X' && gameboard[1][1] == 'X' && gameboard[2][0] == 'X')
  {
    return true;
  }          
return false;
}

boolean Game::checkWinO()
{
  for(int i = 0; i<3; i++)
  {
    if(gameboard[i][0] == 'O' && gameboard[i][1] == 'O' && gameboard[i][2] == 'O')
    return true;      
  }     
  for(int i = 0; i<3; i++)
  {
    if(gameboard[0][i] == 'O' && gameboard[1][i] == 'O' && gameboard[2][i] == 'O')
    return true;
  }     
  if(gameboard[0][0] == 'O' && gameboard[1][1] == 'O' && gameboard[2][2] == 'O')
  {
    return true;
  } 
  if(gameboard[0][2] == 'O' && gameboard[1][1] == 'O' && gameboard[2][0] == 'O')
  {
    return true;
  }   
return false;
}


boolean Game::tie()
{
  for(int i = 0; i<3; i++)
  {
    for(int a = 0; a<3; a++)
    {
      if(gameboard[i][a] == '~')
      {
        return false;
      }
    }
  }
return true;
}

void Game::printboard()
{
  for(int b = 0; b<3; b++)
  {
    for(int c = 0; c<3; c++)
    {
      Serial.print(gameboard[b][c]);
    }
   Serial.println("");
  }
}

boolean Game::spotvacant(int row, int column)
{
  if (gameboard[row][column] == '~')
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Game::getRow()
{
  return _row;
}

int Game::getColumn()
{
  return _column;
}


void Game::blockWin()
{
//first two (left to right)
    for (int i = 0; i < 3; i ++)
    {
        if ((gameboard[i][0] == gameboard[i][1]) && (gameboard[i][2]== '~'))
        {
            gameboard [i][2] = 'O';
            _row = i; _column = 2;
            return;
        }
        
        if ((gameboard[0][i] == gameboard[1][i]) && (gameboard [2][i] == '~'))
        {
            gameboard [2][i] = 'O';
            return;
        }
                
    }
    
    //last two (left to right)
    for (int h = 0; h < 3; h++)
    {
        if ((gameboard[h][1] == gameboard[h][2]) && (gameboard[h][0]== '~'))
        {
            gameboard [h][0] = 'O';
            return;
        }
        
        if((gameboard[1][h]== gameboard[2][h]) && (gameboard [0][h] == '~'))
        {
            gameboard[0][h] = 'O';
            return;
        }
    }
    
    //diagonals
    
    if ((gameboard[0][0] == gameboard[1][1]) && (gameboard [2][2] == '~'))
    {
        gameboard [2][2]= 'O';
        return;
    }
    
    else if((gameboard[1][1] == gameboard [2][2]) && (gameboard [0][0] == '~'))
    {
        gameboard [0][0] = 'O';
        return;
    }
    
    else if((gameboard[0][2] == gameboard [1][1]) && (gameboard[2][0] == '~'))
    {
        gameboard [2][0] = 'O';
        return;
    }
    
    else if((gameboard[2][0] == gameboard [1][1]) && (gameboard[0][2] == '~'))
    {
        gameboard[0][2] = 'O';
        return;
    }
    else
    {
        int cRow = random(0, 4);
        int cColumn = random(0, 4);
        
        while(gameboard[cRow-1][cColumn-1] != '~')
        {
          cRow = random(0, 4);
          cColumn = random(0, 4);
        }
        
        gameboard[cRow-1][cColumn-1] = 'O';
    }
}
