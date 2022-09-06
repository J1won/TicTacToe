

#include "Board.h"

Board::Board () : board {{'.', '.', '.'} , {'.', '.', '.'} , {'.', '.', '.'} }
{}

void Board::showBoard()
{
     for(int r = 0; r < rows; r++)
     {
          for(int c = 0; c < cols; c++)
          {
               cout << " " << board[r][c] << " ";
          }
          cout << "\n";
     }
     cout << "\n";
}

void Board::makeMove(char piece, char row, int col)
{
     
     int r;
     switch(row)
     {
          case 'A':
               r = 1;
               break;
          case 'B':
               r = 2;
               break;
          case 'C':
               r =3;
               break;
     }
     board[r-1][col-1] = piece;
}
void Board::resetBoard()
{
     for(int r = 0; r < rows; r++)
     {
          for(int c = 0; c < cols; c++)
          {
               board[r][c] = '.';
          }
          cout << "\n";
     }
}

//checks each diagonal, row, and col 
char Board::isDone()
{
    // char outcome = 'f';
     //1st row
     if(board[0][0] != '.' && board[0][0] == board[0][1] && board[0][1] == board[0][2] )
          return board[0][0];

     //2nd row
     else if(board[1][0] != '.' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
          return board[1][0];

     //3rd row
     else if(board[2][0] != '.' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
          return board[2][0];

     //1st col
     else if(board[0][0] != '.' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
          return board[0][0];

     //2nd col
     else if(board[0][1] != '.' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
          return board[0][1];

     //3rd col
     else if(board[0][2] != '.' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
          return board[0][2];

     //upper_left_lower_right_diag
     else if(board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
          return board[0][0];

     //upper_right_lower_left diag
     else if(board[2][0] != '.' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
          return board[2][0];
     else if(board[0][0] != '.' && this->isFull())
          return 'd';
     else
          return 'f';

}
bool Board::isFull()
{
     for(int r = 0; r < rows; r++)
     {
          for(int c = 0; c < cols; c++)
          {
               if(board[r][c] == '.')
                    return false;
          }
     }
     return true;
}
double Board::utility(int depth)
{
     if (this->isDone() == 'O') //win
     {
          return (1 - 0.1*depth);
     }
     else if (this->isDone() == 'd') //draw
     {
          return 0;
     }
     return (-1 + 0.1*depth); //'X' wins
}
