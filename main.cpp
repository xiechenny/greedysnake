#include <iostream>
#include "game.hpp"
#include "printer.hpp"

void printMap( const std::vector<std::vector<char> > &map);


int main()
{
    std::cout<<"Welcom to Greedy Snake!"<<std::endl;
	STDPrinter printer;
	Game curgame(&printer);
	curgame.run();
}
