#include <iostream>
#include "ttt.h"
#include "minimax.h"
using namespace std;

void RunGame(int gameSize, bool useAI=false);
string PickXorO();

int main()
{
  char choice;
  bool repeat = true;
  while (repeat) {
    cout << "(H)uman-vs-human, (C)omputer-vs-human, or (Q)uit? ";
    cin >> choice;
    switch (toupper(choice)) {
    case 'H':
      RunGame(3); break;
    case 'C':
      RunGame(3, true); break;
    case 'Q':
      repeat = false; break;
    default:
      cout << "** Invalid choice.\n";
    }
    cout << "\n\n\n";
  }
}

void RunGame(int gameSize, bool useAI)
{
  TicTacToe * theGame = new TicTacToe(gameSize);
  MinimaxBrain * brain;
  string humanPlayer;
  int userRow;
  int userCol;

  if (useAI)
    {
      brain = new MinimaxBrain(theGame);
      cout << "\n\n\n";
      humanPlayer = PickXorO();
    }

  cout << "\n\n\n";

  while (!theGame->BoardIsFull() && theGame->Winner() == "")
    {
      theGame->Show();
      if (useAI && theGame->WhoseTurn() != humanPlayer)
	{
	  brain->AITurn();
	}
      else
	{
	  cout << "Player " << theGame->WhoseTurn() <<  ", please enter a row and column:\n";
	  cin >> userRow >> userCol;
	  theGame->MakeMove(Position(userRow, userCol));
	}
    }

  theGame->Show();

  string winner = theGame->Winner();
  cout << "==== GAME OVER ====\n";
  if (winner == "")
    {
      cout << "   It's a tie!\n";
    }
  else
    {
      if (useAI)
	cout << "   " << (winner == humanPlayer ? "human" : "computer") << " wins!\n";
      else
	cout << "   Player " << winner << " wins!\n";
    }
  cout << "===================\n";
 
  delete theGame;
  if (useAI)
    delete brain;
}

string PickXorO()
{
  char answer;
  cout << "Human, do you want to be X and go first (y/n)? ";
  while (true)
    {
      cin >> answer;
      switch (toupper(answer)) 
	{
	case 'Y':
	  return "X";
	case 'N':
	  return "O";
	default:
	  cout << "Please pick Y or N: ";
	  cin >> answer;
	}
      
    }
}
