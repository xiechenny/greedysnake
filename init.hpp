#ifndef INIT_H
#define INIT_H
#include <cstddef>

typedef struct
{
	size_t x;
	size_t y;
} Pointer_t;

class Rcode
{
	public:
	static const int RUN = 0;
	static const int IOERR = -1;
	static const int WIN = 1;
	static const int LOSE = 2;
	
};

class Marks
{
	public:
	static const char MAP_FRUIT = 'O';
	static const char MAP_SNAKE_BODY = 'X';
	static const char MAP_BLANK = ' ';
};

#endif
