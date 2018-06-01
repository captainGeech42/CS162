CC = g++
C_FLAGS = -Wall -Werror -D MAKE
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

$(exe): ant.o bee.o driver.o entity.o game_manager.o ui_manager.o thrower.o fire.o longthrower.o shortthrower.o wall.o ninja.o bodyguard.o
	$(CC) $(C_FLAGS) -o $(exe) ant.o bee.o driver.o entity.o game_manager.o ui_manager.o thrower.o fire.o longthrower.o shortthrower.o wall.o ninja.o bodyguard.o 

ant.o: ant.cpp ant.hpp
	$(CC) $(C_FLAGS) -c ant.cpp

bee.o: bee.cpp bee.hpp
	$(CC) $(C_FLAGS) -c bee.cpp

driver.o: driver.cpp
	$(CC) $(C_FLAGS) -c driver.cpp

entity.o: entity.cpp entity.hpp
	$(CC) $(C_FLAGS) -c entity.cpp

game_manager.o: game_manager.cpp game_manager.hpp
	$(CC) $(C_FLAGS) -c game_manager.cpp

ui_manager.o: ui_manager.cpp ui_manager.hpp
	$(CC) $(C_FLAGS) -c ui_manager.cpp

thrower.o: ants/thrower.cpp ants/thrower.hpp
	$(CC) $(C_FLAGS) -c ants/thrower.cpp

fire.o: ants/fire.cpp ants/fire.hpp
	$(CC) $(C_FLAGS) -c ants/fire.cpp

longthrower.o: ants/longthrower.cpp ants/longthrower.hpp
	$(CC) $(C_FLAGS) -c ants/longthrower.cpp

shortthrower.o: ants/shortthrower.cpp ants/shortthrower.hpp
	$(CC) $(C_FLAGS) -c ants/shortthrower.cpp

wall.o: ants/wall.cpp ants/wall.hpp
	$(CC) $(C_FLAGS) -c ants/wall.cpp

ninja.o: ants/ninja.cpp ants/ninja.hpp
	$(CC) $(C_FLAGS) -c ants/ninja.cpp

bodyguard.o: ants/bodyguard.cpp ants/bodyguard.hpp
	$(CC) $(C_FLAGS) -c ants/bodyguard.cpp

clean:
	$(RM) *.o *.out $(exe) *.gch peda*

compress:
	tar zcvf assign4.tar.gz Makefile *.?pp
