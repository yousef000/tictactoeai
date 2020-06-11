#ifndef MINIMAX_H
#define MINIMAX_H

#include "ttt.h"
struct AIMove
{
    AIMove(){};
    AIMove(int score)
    {
        this->score = score;
    }
    int r;
    int c;
    int score;
};

class MinimaxBrain
{
 private:
    TicTacToe * game;
    int score;

 public:
    MinimaxBrain(TicTacToe * game);
    void AITurn();
    string playerSymbol;
    string AISymbol;
    int move;
  
 private:
  /// These are SUGGESTED private methods:
    AIMove PickBestMove(TicTacToe gameState, string WhosTurn);
    
};


#endif
