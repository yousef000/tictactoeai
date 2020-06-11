#include <iostream>
#include <algorithm>
#include "ttt.h"
using namespace std;

string TicTacToe::Winner(){
  /**  Evaluate the current game state to determine if anyone has already one
  /**  Return "X", "O", or "" (empty string) */
  
  for(int r = 0; r < 3; r++)
  {
    if(board.getAt(r, 0) != " " && board.getAt(r, 0) ==  board.getAt(r, 1) )
        if(board.getAt(r, 1) == board.getAt(r, 2))
            return board.getAt(r, 0);
    
    if(board.getAt(0, r) != " " && board.getAt(0, r) ==  board.getAt(1, r) )
        if(board.getAt(1, r) == board.getAt(2, r))
            return board.getAt(0, r);
    
    if(r == 0)
        if(board.getAt(r, r) != " " && board.getAt(r, r) == board.getAt(r+1, r+1))
            if(board.getAt(r+2, r+2) == board.getAt(r+1, r+1))
                return board.getAt(r, r);
    if(r == 1)
        if(board.getAt(r, r) != " " && board.getAt(r, r) == board.getAt(r-1, r+1))
            if(board.getAt(r-1, r+1) == board.getAt(r+1, r-1))
                return board.getAt(r, r);
  }

  bool istied = true;
  for(int i = 0; i < 3; i++)
      for( int c = 0; c < 3; c++)
          if(board.getAt(i, c) == " ")
              istied = false;
              
  
  if(istied == true)
      return "tied";
  

  return "";
}


TicTacToe::TicTacToe(int boardSize) 
  : board(boardSize, boardSize)
{
  moves = 0;
  for (int r = 0; r < boardSize; r++)
    for (int c = 0; c < boardSize; c++)
      {
        board.setAt(r, c, " ");
        openPositions.push_back(Position(r, c));
      }
}

void TicTacToe::Show() const
{
  Grid<string>& b = const_cast<Grid<string>& >(board);
  int numRows = b.numRows();
  int numCols = b.numCols();
  cout << "\n";

  for (int r = 0; r < numRows; r++){
    if (r > 0){
      cout << " ";
      for (int c = 0; c < numCols; c++){
        if (c > 0)
          cout << "+";
        cout << "-"; 
      }

      cout << "\n";
    }

    cout << " ";
    for (int c = 0; c < numCols; c++){
      if (c > 0)
        cout << "|";
      cout << b.getAt(r, c);
    }
    cout << "\n";
  }
  cout << "\n";
}

string TicTacToe::WhoseTurn() const{
  return (moves%2 == 0 ? "X" : "O");
}

vector<Position> TicTacToe::AvailableMoves() const{
  return openPositions;
}

bool TicTacToe::BoardIsFull() const{
  return (openPositions.size() == 0);
}


void TicTacToe::MakeMove(Position movePosition){
  int r = movePosition.row;
  int c = movePosition.col;
  if (!board.inBounds(movePosition.row, movePosition.col)){
    cout << movePosition << " is out of bounds.\n";
    cout << "** Game state is unchanged.\n";
  }
  else if (board.getAt(r, c) != " "){
    cout << movePosition << " is not available.\n";
    cout << "** Game state is unchanged.\n";
  }
  else{
    string symbol = WhoseTurn();
    board.setAt(movePosition.row, movePosition.col, symbol);      
    openPositions.erase(find(openPositions.begin(), openPositions.end(), movePosition));
    moves++;
  }
}


