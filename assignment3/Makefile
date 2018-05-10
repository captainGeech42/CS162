CC = g++
C_FLAGS = -Wall -Werror -D MAKE
exe = assignment3

all: $(exe)

debug: C_FLAGS += -g -D DEBUG
debug: $(exe)

gdb: debug
	gdb $(exe)

run: $(exe)
	./$(exe)

$(exe): apartment.o business.o driver.o game_manager.o property.o
	$(CC) $(C_FLAGS) -o $(exe) apartment.o business.o driver.o game_manager.o property.o 

apartment.o: apartment.cpp
	$(CC) $(C_FLAGS) -c apartment.cpp

business.o: business.cpp
	$(CC) $(C_FLAGS) -c business.cpp

driver.o: driver.cpp
	$(CC) $(C_FLAGS) -c driver.cpp

game_manager.o: game_manager.cpp
	$(CC) $(C_FLAGS) -c game_manager.cpp

property.o: property.cpp
	$(CC) $(C_FLAGS) -c property.cpp

clean:
	$(RM) apartment.o business.o game_manager.o property.o driver.o *.out $(exe) *.gch peda*

compress:
	tar zcvf assign3.tar.gz Makefile helper.* apartment.?pp business.?pp game_manager.?pp list.?pp property.?pp driver.?pp
