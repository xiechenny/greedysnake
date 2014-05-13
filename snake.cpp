#include "snake.hpp"
#include <cstdlib>
const int Snake::stepmove[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void Snake::setNewFruit(std::vector<std::vector<char> > &map)
{
	size_t mapsize = map.size();

	Pointer_t p;

	do{
		p.x = std::rand()%mapsize;
		p.y = std::rand()%mapsize;
	}while(map[p.x][p.y]!=' ');
	map[p.x][p.y] = Marks::MAP_FRUIT;
};

Snake::Snake(size_t direction, size_t x, size_t y)
{
	resetSnake(direction,x,y);
};

Snake::~Snake(){};

void Snake::resetSnake(size_t direction, size_t x, size_t y)
{
	this->direction = direction;
    this->hposition.x = x;
    this->hposition.y = y;
};

void Snake::init(std::vector<std::vector<char> > &map)
{
	int mapsize = map.size();
	map[hposition.x][hposition.y] = Marks::MAP_SNAKE_BODY;
	len = 1;
	body.push(hposition);
};

int Snake::move(std::vector<std::vector<char> > &map)
{
	int mapsize = map.size();

	hposition.x +=stepmove[direction][0];
	hposition.y +=stepmove[direction][1];

	if((hposition.x<mapsize)&&(hposition.y<mapsize))
	{
		if(map[hposition.x][hposition.y]==Marks::MAP_FRUIT){
			map[hposition.x][hposition.y] = Marks::MAP_SNAKE_BODY;
			body.push(hposition);
			len++;
			setNewFruit(map);
		}
		else{
			Pointer_t &p = body.front();
			map[p.x][p.y] = Marks::MAP_BLANK;
			body.pop();
			if(map[hposition.x][hposition.y]==Marks::MAP_BLANK)
			{
				map[hposition.x][hposition.y]=Marks::MAP_SNAKE_BODY;
				body.push(hposition);
			}
			else return Rcode::LOSE;
		}
	}
	else return Rcode::LOSE;

	return Rcode::RUN;
};

void Snake::setDirection(size_t d)
{
	this->direction = d;	
};
	
	
