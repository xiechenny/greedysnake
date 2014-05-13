#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <curses.h>
#include <vector>
#include "init.hpp"

class Printer{
	public:
	virtual ~Printer(){};
	virtual void printMap(const std::vector<std::vector<char> > &map) = 0;
	virtual void printLine(const std::string &content) = 0;
	virtual int getKey() = 0;
	virtual void init(){};
};

class STDPrinter : public Printer
{
	private:
		std::string tips;

	public:
	void printMap( const std::vector<std::vector<char> > &map ){
		std::cout<<tips<<std::endl;
		//top edge
	    for(size_t j=0;j<map.size();j++)
	          std::cout<<'-';
	    std::cout<<std::endl;

	    //game area
	    for(size_t i=0;i<map.size();i++){
	        for(size_t j=0;j<map[i].size();j++)
	             std::cout<<map[i][j];
	        std::cout<<std::endl;
									    }

	    //bottom edge
	    for(size_t j=0;j<map.size();j++)
	        std::cout<<'-';
	    std::cout<<std::endl;
	};
	
	void printLine(const std::string &content)
	{
		std::cout<<content<<std::endl;
	};

	void init()
	{
		tips = "Control, up:w, down:s, left:a; right:d ";
	};

	int getKey()
	{
		char key;
		int ret = 0;
		std::cin>>key;
		switch (key){
			case 'w': 
				ret = 3;
				break;
			case 's':
				ret = 2;
				break;
			case 'a':
				ret = 1;
				break;
			case 'd':
				ret = 0;
				break;
		}
		return ret;
	};
};

class CursesPrinter : public Printer{
	public:
	void printMap(const std::vector<std::vector<char> > &map);
	void printLine(const std::string &content);
	int getKey();
	void init();
};

#endif
