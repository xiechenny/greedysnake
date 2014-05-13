#ifndef SNAKE_H
#define SNAKE_H

#include "init.hpp"
#include <queue>

class Snake
{
	private:
	static const int stepmove[4][2];
	size_t direction;
	size_t len;
	Pointer_t hposition;
	std::queue<Pointer_t> body;

	public:
	static const int moveUP = 3;
	static const int moveDown = 2;
	static const int moveLeft = 1;
	static const int moveRight = 0;

	Snake(size_t direction = moveRight, size_t x = 0,size_t y = 0);
	void resetSnake(size_t direction, size_t x, size_t y);
	void init(std::vector<std::vector<char> > &map);
	int move(std::vector<std::vector<char> > &map);
	void setDirection(size_t d);
	void setNewFruit(std::vector<std::vector<char> > &map);
	~Snake();
};

#endif

