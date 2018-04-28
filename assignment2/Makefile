CC = g++
C_FLAGS = -g -Wall -Werror -D MAKE
exe = assignment2

all: $(exe)

run: $(exe)
	./$(exe)

$(exe): pizza.o menu.o restaurant.o driver.o helper.o order_manager.o
	$(CC) $(C_FLAGS) -o $(exe) pizza.o menu.o restaurant.o driver.o helper.o order_manager.o

driver.o: driver.cpp
	$(CC) $(C_FLAGS) -c driver.cpp

pizza.o: pizza.cpp pizza.hpp
	$(CC) $(C_FLAGS) -c pizza.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(C_FLAGS) -c menu.cpp

restaurant.o: restaurant.cpp restaurant.hpp
	$(CC) $(C_FLAGS) -c restaurant.cpp

order_manager.o: order_manager.cpp order_manager.hpp
	$(CC) $(C_FLAGS) -c order_manager.cpp

clean:
	$(RM) pizza.o menu.o restaurant.o driver.o order_manager.o *.out $(exe) *.gch peda*

compress:
	tar zcvf assign2.tar.gz pizza.hpp pizza.cpp menu.hpp menu.cpp restaurant.hpp restaurant.cpp Makefile helper.hpp helper.o
