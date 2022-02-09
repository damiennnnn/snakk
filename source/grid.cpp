#include "grid.h"

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    

Grid::Grid(){

	for (int i=0 ; i < PELLET_COUNT; i++){
		int x= rand() % GRID_WIDTH;
		int y= rand() % GRID_HEIGHT;

		pellets.push_back(std::make_pair(x,y));
	}


	snake_head = std::make_pair(32,32);
	direction = std::make_pair(1, 0);

}

void Grid::NewPellets(){
	pellets.clear();
	for (int i=0 ; i < PELLET_COUNT; i++){
		int x= rand() % GRID_WIDTH;
		int y= rand() % GRID_HEIGHT;

		pellets.push_back(std::make_pair(x,y));
	}

}
void Grid::Update(){

	bool _eaten = false;


	if (_eaten){
		snake_tail.push_back(snake_head);
	}

	snake_head = (snake_head+direction);

}

void Grid::Draw(){

	// snake draw
	int snakex = snake_head.first * 4;
	int snakey = snake_head.second * 4;

	glBoxFilled(snakex,snakey,snakex +2,snakey+2,RGB15(15,15,15));
	for (int i =0 ; i < pellets.size(); i++){
		glBoxFilled(pellets[i].first*4, pellets[i].second*4, (pellets[i].first*4) +2,
		 (pellets[i].second*4) + 2, RGB15(0,15,0));
	}
}

int Grid::GetLength(){
	return snake_tail.size();
}

void Grid::SnakeLeft(){
	direction = std::make_pair(-1,0);
}
void Grid::SnakeRight(){
	direction = std::make_pair(1,0);
}
void Grid::SnakeUp(){
	direction = std::make_pair(0,1);
}
void Grid::SnakeDown(){
	direction = std::make_pair(0,-1);
}

std::pair<int,int> Grid::SnakePos(){
	return snake_head;
}