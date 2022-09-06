//
//terminal commands
// input either: 
// 1. move 'piece' 'row' 'col'
//   move X B 2  -- moves piece X to row B col 2

// 2. choose 'piece'
//  choose O     -- chooses a spot for O using minimax & pruning

//terminate when end state is reached and print and outcome

//Jiwon Lee 03/04/2022

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Board.h"
#include "Game.h"

using namespace std;


int main(int argc, char *argv[])
{
     Game gm = Game();
    
     string initCmd;

     cout << "Welcome to Tic-Tac-Toe" <<endl;

     bool stop = false;

     while(!stop)
     {
          cout << "\n>" ;
          std::getline(cin, initCmd);
          std::istringstream iss(initCmd);
          
          if (!initCmd.compare("show"))
          { //show curr state of board
               cout << "you clicked show" << endl;
               gm.currState.showBoard();
          }
          else if (!initCmd.compare("reset"))
          {
               cout << "you clicked reset" << endl;
               gm.currState.resetBoard();
               gm.currState.showBoard();
          }//////
          
          else if (initCmd.rfind("move", 0) == 0)
          {
               string cmd;
               char p;
               char row;
               int col;
               iss >> cmd;
               iss >> p;
               iss >> row;
               iss >> col;

               gm.currState.makeMove(p, row, col);
               gm.currState.showBoard();
          }
          else if (initCmd.rfind("choose", 0) == 0)
          {
               string cmd;
               char p;
               iss >> cmd;
               iss >> p;


               //void makeMove(char piece, char row, int col);
               gm.setBoard(gm.minimax(p));
               gm.currState.showBoard();
          }
          else if (!initCmd.compare("pruning on"))
          {
               gm.pruning = true;
               cout << "pruning = " << gm.pruning << endl;
          }
          else if  (!initCmd.compare("pruning off"))
          {
               gm.pruning = false;
               cout << "pruning = " << gm.pruning << endl;

          }
          else if  (!initCmd.compare("pruning"))
          {
               cout << "pruning = " << gm.pruning << endl;
          }
          else if (!initCmd.compare("quit"))
          {
               cout << "The loop is terminating" <<endl;
               stop = true;
          }
          
          if(gm.currState.isDone() != 'f')
          {
               switch(gm.currState.isDone())
               {
                    case 'd':
                         cout << "It is a Draw" <<endl;
                         stop = true;
                         break;
                    case 'X':
                         cout << "X wins!" <<endl;
                         stop = true;
                         break;
                    case 'O':
                         cout << "O wins!" <<endl;
                         stop = true;
                         break;
               } 
          }
     }
}
