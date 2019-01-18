CXX=g++
CXXFLAGS=-Wall -g

all: game

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

game: utility.o cards.o main.o
	g++ utility.o cards.o main.o -g -o game

cards.o: cards.h cards.cpp
	$(CXX) $(CXXFLAGS) -c cards.cpp

utility.o: utility.h utility.cpp
	$(CXX) $(CXXFLAGS) -c utility.cpp

clean:
	rm game main.o cards.o



