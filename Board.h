

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <utility>
#include <string>       // std::string
#include <iostream>
#include <vector>


using namespace std;



class Board{
public:
     char board[3][3];
     int rows = 3;
     int cols = 3;
     
     Board();

     void showBoard();
     void makeMove(char piece, char row, int col);
     void resetBoard();
     char isDone();
     bool isFull();
     double utility(int depth);


};



#endif

