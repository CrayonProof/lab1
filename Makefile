all: 
	g++ -std=c++11 -o lab1Make main.cpp Arena.cpp Fighter.cpp Robot.cpp Archer.cpp Cleric.cpp

clean:
	rm -f lab1Make