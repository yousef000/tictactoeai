#ifndef GRID_H
#define GRID_H

#include "library-includes/grid.h"
#include <vector>
using namespace std;

struct Position
{
  int row;
  int col;

  Position(int row, int col) { this->row = row; this->col = col; }
  bool operator==(const Position& other) { return row == other.row && col == other.col; }
  friend ostream& operator<<(ostream& os, const Position& p) { os << "(" << p.row << ", " << p.col << ")"; return os;}
};

class TicTacToe
{
private:
  
  vector<Position> openPositions;
  int moves;

public:
  Grid<string> board;
  /// Method you must implement
  string Winner();

  /// Constructor
  TicTacToe(int boardSize);

  /// Accessors
  void Show() const;  /// Displays the current state of the board
  string WhoseTurn() const; /// Returns X or O (X is always the first player)
  vector<Position> AvailableMoves() const; /// Returns a list of all positions current available on the board
  bool BoardIsFull() const; /// Returns true if the board is completely full (no open spaces)
  
  /// Mutators
  void MakeMove(Position pos); /// Places the current player's symbol in the given position
};

#endif // GRID_H
