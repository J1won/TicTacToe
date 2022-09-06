CC = g++
ttt: ttt.o Board.o Game.o
	$(CC) -o ttt ttt.o Board.o Game.o
ttt.o: ttt.cpp
	$(CC) -std=c++11 -c ttt.cpp
Board.o: Board.cpp Board.h
	$(CC) -std=c++11 -c Board.cpp
Game.o: Game.cpp Game.h
	$(CC) -std=c++11 -c Game.cpp
clean:
	rm *.o