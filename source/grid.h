#include "includes.h"
#define GRID_HEIGHT 48
#define GRID_WIDTH 64
#define PELLET_COUNT 10
class Grid{
private:
	
	std::vector<std::pair<int,int>> pellets;
	std::vector<std::pair<int,int>> snake_tail;
	std::pair<int,int> direction;

	int len;
public:
	std::pair<int,int> snake_head;
	Grid();
	bool Update(); // returns true if snake is dead, reset
	void NewPellets();
	void Draw();
	int GetLength();
	// snake movement control
	void SnakeLeft();
	void SnakeRight();
	void SnakeUp();
	void SnakeDown();

	std::pair<int,int> SnakePos();
};