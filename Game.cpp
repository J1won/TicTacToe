
#include "Game.h"

Game::Game () 
{
     Board bd;
     pruning = false;
     currState = bd;
}

//takes the current state and returns possible other states
vector<Board> Game::successors(char p, Board state)
{
     Board tempCurrState = state; //copy the state

     vector<Board> moves;
     for(int r = 0; r < 3; r++)
     {
          for(int c = 0; c < 3; c++)
          {
               //for every empty spot, 
               //add a player move, add to vector, reset board
               if(state.board[r][c]  == '.')
               {
                    tempCurrState.board[r][c] = p; 
                    moves.push_back(tempCurrState);
               }
               tempCurrState = state;
          }
     }
     return moves;
}


Board Game::minimax(char p)
{
     pair<double, Board> va;
     pair<double, Board> valO;
     valO.first = -1000000;
     pair<double, Board> valX;
     valX.first = 10000000;
     Board currStTemp = currState;

     //for each immediate successor
     for(Board a : successors(p, currStTemp))
     {
          numNodes++;
          if( p == 'O')
          {
               //call min(X) on each next moves of 'O'
               va = minValue(a, 0 , 'X', -10000000, 100000000);
               if(va.first > valO.first)
               {
                    valO.first = va.first; 
                    valO.second = a;
               }
               cout << "move: " <<endl;
               a.showBoard();
               cout << "mm score: " << va.first << endl;
          }
          else
          {
               va = maxValue(a, 0 , 'O', -10000000, 100000000);
               //trying to find min of the maxValues
               if(va.first < valX.first)
               {
                    valX.first = va.first;
                    valX.second = a;
               }
               cout << "move: " <<endl;
               a.showBoard();
               cout << "mm score: " << va.first<<endl;
          }

     }
     cout << "number of nodes searched: " << numNodes << endl;
     numNodes = 0;
     if(p == 'O')
     {
          return valO.second;
     }
     return valX.second;
}



pair<double, Board> Game::maxValue(Board state, int depth , char pp, int al, int be)
{
     //char pp_temp;
     Board stateTemp = state;
     //cout << "P: "<< player <<endl;
     pair<double, Board> valMv;
     pair<double, Board> valMvTemp;
     if(state.isDone() == 'X' || state.isDone() == 'O' || state.isDone() == 'd')
     {
          valMv.first = state.utility(depth);
          return valMv;
     }
     valMv.first = -100000;
     for(Board a : successors('O', stateTemp))
     {
          numNodes++;
          valMvTemp = minValue(a , depth+1, 'X', al, be);
          if(valMvTemp.first > valMv.first)
          {
               valMv.first = valMvTemp.first;
               valMv.second = a;
               al = max((double)al, valMv.first);
          }
          if(pruning)
          {
               //implements pruning only if pruning is True;
               if(valMv.first >= be)
                    return valMv;
          }
     }
     return valMv;
}

//X starts off at minValue
pair<double, Board> Game::minValue(Board state, int depth, char pp , int al, int be)
{
     pair<double, Board> valMv;
     pair<double, Board> valMvTemp;
     Board stateTemp = state;
     if(state.isDone() == 'X' || state.isDone() == 'O' || state.isDone() == 'd')
     {
          valMv.first = state.utility(depth);
          return valMv;
     }
     valMv.first = 100000;
     
     //need opposite player only for successor
     for(Board a : successors('X', stateTemp))
     {
          numNodes++;
          valMvTemp = maxValue(a, depth+1, 'O', al, be);
          if(valMvTemp.first < valMv.first)
          {
               valMv.first = valMvTemp.first;
               valMv.second = a;
               be = min((double)be, valMv.first);
          }
          if(pruning)
          {    //implements pruning only if pruning is True;
               if(valMv.first <= al)
                    return valMv;
          }
     }
     return valMv;
}

void Game::setBoard(Board bd)
{
     currState = bd;
}