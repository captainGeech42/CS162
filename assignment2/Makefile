CC = g++
C_FLAGS = -g -Wall -Werror
exe = assignment2

all: $(exe)

run: $(exe)
	./$(exe)

$(exe): pizza.o menu.o restaurant.o driver.o helper.o
	$(CC) $(C_FLAGS) -o $(exe) pizza.o menu.o restaurant.o driver.o helper.o

driver.o: driver.cpp
	$(CC) $(C_FLAGS) -c driver.cpp

pizza.o: pizza.cpp pizza.h
	$(CC) $(C_FLAGS) -c pizza.cpp

menu.o: menu.cpp menu.h
	$(CC) $(C_FLAGS) -c menu.cpp

restaurant.o: restaurant.cpp restaurant.h
	$(CC) $(C_FLAGS) -c restaurant.cpp

clean:
	$(RM) pizza.o menu.o restaurant.o driver.o *.out $(exe) *.gch peda*

compress:
	tar zcvf assign2.tar.gz pizza.h pizza.cpp menu.h menu.cpp restaurant.h restaurant.cpp Makefile helper.hpp helper.o
