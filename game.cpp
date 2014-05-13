#include "game.hpp"
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

// Game class
Game::Game(Printer *_printer,const size_t size): smartMode(false)
{
	printer = _printer;
	mapsize = size;
	map.resize(mapsize);		
	for(size_t i=0;i<mapsize;i++)
	{
		map[i].resize(mapsize, ' ');
	}
};

Game::~Game(){};

const std::vector<std::vector<char> > &
Game::getMap(){return map;	};

void Game::caculatePath(std::vector<size_t> &movequeue)
{
	for(size_t i = 0;i<10;i++)
		movequeue.push_back(i%5);
}


void *keyListener(void *_game)
{
	Game *game = (Game *)_game;

	while(game->getState()==Rcode::RUN){
		(game->getSnake()).setDirection((game->getPrinter())->getKey());
	//	std::cout<<"key "<<key<<std::endl;
	}
};


int Game::run(){	
	//first check output printer
	if(printer==NULL){
		std::cerr<<"GreedySnake: Error, no printer is set!"<<std::endl;
		return Rcode::IOERR;
	}

	//Begin to Run
	//2 for lose; 1 for win, -x for error
	state = Rcode::RUN;

	//init 
	printer->init();
	std::vector<size_t> movequeue;
	movequeue.resize(mapsize*mapsize);
	snake.init(map);	
	snake.setNewFruit(map);
	if(smartMode)
		caculatePath(movequeue);
	printer->printMap(map);

	pthread_t lthread;
	int	r = pthread_create(&lthread, NULL, keyListener, (void *)this);

	while(state==Rcode::RUN){
		sleep(1);
		state = snake.move(map);
	
		if(state==Rcode::LOSE){
			printer->printLine("Game Over!");
		}
		else printer->printMap(map);
	}

	//pthread_join(lthread, NULL);
	return state;
}
