# source files
SRC	=	snake.cpp printer.cpp game.cpp
SRCMAIN = main.cpp
# object files
OBJ =  $(SRC:.cpp=.o)
# compiler
CC	=	g++
# include file
#INCLUDE = -I/usr/include/boost  
# link parameter
LINKPARAM = -lpthread -lncurses 

# program name
PROG	=	greedysnake
# for developmemt
# CFLAGS
CFLAGS = -O

:snake
snake :	$(SRCMAIN) $(OBJ) $(SRC:.cpp=.hpp)
	$(CC) -o $(PROG) $(INCLUDE) $(LINKPARAM) $(SRCMAIN) $(OBJ)
$(OBJ) : %.o : %.cpp init.hpp
	$(CC) -c $(CFLAGS) $<
clean :
	rm -rf *.o *.gch $(PROG)
