#include <iostream>
#include "minimax.h"
#include "ttt.h"
#include <vector>
using namespace std;

MinimaxBrain::MinimaxBrain(TicTacToe * game, int move)
{
    this->game = game;
    this->move = move;
    playerSymbol = game->WhoseTurn();
    if(playerSymbol == "X")
        AISymbol = "O";
    else
        AISymbol = "X";
    
    
}

void MinimaxBrain::AITurn()
{
    AIMove bestMove = PickBestMove(*game, AISymbol);
    Position * chosenMove;
    chosenMove = new Position(bestMove.r, bestMove.c);
    cout << game->WhoseTurn() << " chooses (" << chosenMove->row << "," << chosenMove->col << ")" << endl;
    game->MakeMove(*chosenMove);
    
}
AIMove MinimaxBrain::PickBestMove(TicTacToe gameState, string WhosTurn)
{
    //return points
    string winner = gameState.Winner();
    if(winner == AISymbol)
        return AIMove(10);
    else if(winner == playerSymbol)
        return AIMove(-10);
    else if(winner == "tied")
        return AIMove(0);
    
    vector<AIMove> moves;
    //Do the recursion function
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            
            if(gameState.board.getAt(r, c) == " ")
            {
                
                AIMove move;
                move.r = r;
                move.c = c;
                gameState.board.setAt(r, c, WhosTurn);
                if(WhosTurn == AISymbol)
                    move.score = PickBestMove(gameState, playerSymbol).score;
                else
                    move.score = PickBestMove(gameState, AISymbol).score;
                
                moves.push_back(move);
                gameState.board.setAt(r, c, " ");
            }
        }
    }
    
    //Pick the best move for current player
    int bestMove = 0;
    if(WhosTurn == AISymbol)
    {
        int bestScore = -1000000;
        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i].score > bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
            
        }
    }
    else
    {
        int bestScore = 1000000;
        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i].score < bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
            
        }
        
    }
    
    return moves[bestMove];
    
}

