#ifndef GAME_H
#define GAME_H

#include <vector>
#include "init.hpp"
#include "printer.hpp"
#include "snake.hpp"

class Game
{
	//members
	private:
		Printer *printer;
		std::vector<std::vector<char> > map;
		Snake snake;
		size_t mapsize;
		bool smartMode;
		int state;

	//methods
	private:	
		void caculatePath(std::vector<size_t> &movequeue);

	public:
		Game(Printer *printer = NULL,const size_t size=10);
		~Game();
		const std::vector<std::vector<char> > &getMap();
		void resetSnake(size_t direction, size_t x, size_t y)
		{	snake.resetSnake(direction,x,y);	};
		int run();
		Printer *getPrinter(){return printer;};
		Snake &getSnake(){return snake;};
		int getState(){return state;};
};

#endif
