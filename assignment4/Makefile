CC = g++
C_FLAGS = -Wall -Werror -lncurses -D MAKE
exe = assignment4

all: clean $(exe)

debug: C_FLAGS += -g -D DEBUG
debug: all

gdb: clean debug
	gdb $(exe)

run: all
	./$(exe)

valgrind: all
	valgrind --leak-check=full ./$(exe)

$(exe): driver.o ui_manager.o
	$(CC) $(C_FLAGS) -o $(exe) driver.o ui_manager.o

driver.o: driver.cpp
	$(CC) $(C_FLAGS) -c driver.cpp

ui_manager.o: ui_manager.cpp ui_manager.hpp
	$(CC) $(C_FLAGS) -c ui_manager.cpp

clean:
	$(RM) *.o *.out $(exe) *.gch peda*

compress:
	tar zcvf assign4.tar.gz Makefile *.?pp
