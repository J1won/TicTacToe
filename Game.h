

#include <iostream>
#include <utility>
#include <string>       // std::string
#include <iostream>
#include <vector>
#include <algorithm>

#include "Board.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game{
private: 
     int numNodes = 0;
public:
     bool pruning;
     int depth;
     Board currState;
     char player;
     Game();

     vector<Board> successors(char p, Board state);
     Board minimax(char p);
     pair<double, Board> maxValue(Board state, int depth, char pp, int al, int be );
     pair<double, Board> minValue(Board state, int depth , char pp, int al, int be);
     void setBoard(Board bd);
   
};



#endif