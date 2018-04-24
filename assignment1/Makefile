CC = g++
C_FLAGS = -g -Wall -Werror
exe = assignment1

all: $(exe)

run: $(exe)
	./$(exe)

$(exe): helper.o facts.o run_facts.o
	$(CC) $(C_FLAGS) -o $(exe) facts.o run_facts.o helper.o

facts.o: facts.cpp facts.h
	$(CC) $(C_FLAGS) -c facts.cpp

run_facts.o: run_facts.cpp facts.h
	$(CC) $(C_FLAGS) -c run_facts.cpp

clean:
	$(RM) facts.o run_facts.o *.out $(exe) *.gch

compress:
	tar zcvf assign1.tar.gz facts.h facts.cpp run_facts.cpp Makefile helper.hpp helper.o
