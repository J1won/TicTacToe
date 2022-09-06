# csce420-spr22

This program sets player 'X' to always want the minimum score and 
player 'O' to always want the maximum score.


type in 'make' to the command line
(ie. home/user$ make)

type in 'make clean' to remove the .o files

run './ttt'
(ie. home/user$ ./ttt )


The possible commands are:
- 'show'
     shows the current state of the board

- 'reset'
     resets the board to empty board

- 'move <player> <row> <column>'
     player makes a move at given row and column
     (ie. move X A 3   or     move O B 3 )
     possible rows are A, B, and C
     possible columns are 1, 2, and 3

- 'choose <player>'
     computers chooses the best move of given player
     also prints all the possible next moves and its utilty function
     (ie. choose X    or     choose O)

- 'pruning'
     shows the state of pruning

- 'pruning on'
     turns on pruning

- 'pruning off'
     turns off pruning

- 'quit'
     exits program

if you input the wrong command, the program just prompt for another command

