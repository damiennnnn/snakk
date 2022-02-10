#include "grid.h"

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    

void Grid::Init(){
	len=3;
	for (int i=0 ; i < PELLET_COUNT; i++){
		int x= rand() % GRID_WIDTH;
		int y= rand() % GRID_HEIGHT;

		pellets.push_back(std::make_pair(x,y));
	}
	snake_tail.clear();
	snake_head = std::make_pair(32,32);
	direction = std::make_pair(1, 0);
}
Grid::Grid(){
	Init();
}

void Grid::NewPellets(){
	pellets.clear();
	for (int i=0 ; i < PELLET_COUNT; i++){
		int x= rand() % GRID_WIDTH;
		int y= rand() % GRID_HEIGHT;

		pellets.push_back(std::make_pair(x,y));
	}

}
bool Grid::Update(){

	bool _eaten = false;
	int to_remove = -1;
	for (int i =0 ; i < pellets.size(); i++){
		if (pellets[i] == snake_head)
		{
			_eaten = true;
			len	++;
			to_remove = i;
		}

	}
	if (_eaten){
		pellets.erase(pellets.begin() + to_remove);
		pellets.push_back(std::make_pair(rand() % GRID_WIDTH, rand() % GRID_HEIGHT));
	}
	
	for (int i =0 ; i < snake_tail.size() ; i++){
		if (snake_tail[i] == snake_head)
			return true;
	}
	snake_tail.push_back(snake_head);
	if (snake_tail.size() > len)
		snake_tail.erase(snake_tail.begin());
	snake_head = (snake_head+direction);

	return false;
}

void Grid::Draw(){
	for (int i =0 ; i < pellets.size(); i++){
		glBoxFilled(pellets[i].first*4, pellets[i].second*4, (pellets[i].first*4) +2,
		 (pellets[i].second*4) + 2, RGB15(0,15,0));
	}
	for (int i =0 ; i < snake_tail.size(); i++){
		glBoxFilled(snake_tail[i].first * 4, snake_tail[i].second*4, (snake_tail[i].first * 4) + 2 ,
		 (snake_tail[i].second * 4) + 2, RGB15(7+i%8,7+i%8,7+i%8));
	}
		// snake draw
	int snakex = snake_head.first * 4;
	int snakey = snake_head.second * 4;

	glBoxFilled(snakex,snakey,snakex +2,snakey+2,RGB15(15,15,15));
}

int Grid::GetLength(){
	return len;
}

void Grid::SnakeLeft(){
	direction = std::make_pair(-1,0);
}
void Grid::SnakeRight(){
	direction = std::make_pair(1,0);
}
void Grid::SnakeUp(){
	direction = std::make_pair(0,-1);
}
void Grid::SnakeDown(){
	direction = std::make_pair(0,1);
}

std::pair<int,int> Grid::SnakePos(){
	return snake_head;
}