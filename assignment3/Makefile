CC = g++
C_FLAGS = -Wall -Werror -D MAKE
exe = assignment3

all: clean $(exe)

debug: C_FLAGS += -g -D DEBUG
debug: all

gdb: clean debug
	gdb $(exe)

run: $(exe)
	./$(exe)

$(exe): apartment_complex.o business_complex.o business.o citizen.o driver.o game_manager.o helper.o property.o tenant.o
	$(CC) $(C_FLAGS) -o $(exe) apartment_complex.o business_complex.o business.o citizen.o driver.o game_manager.o helper.o property.o tenant.o

apartment_complex.o: apartment_complex.cpp
	$(CC) $(C_FLAGS) -c apartment_complex.cpp

business_complex.o: business_complex.cpp
	$(CC) $(C_FLAGS) -c business_complex.cpp

business.o: business.cpp
	$(CC) $(C_FLAGS) -c business.cpp

citizen.o: citizen.cpp
	$(CC) $(C_FLAGS) -c citizen.cpp

driver.o: driver.cpp
	$(CC) $(C_FLAGS) -c driver.cpp

game_manager.o: game_manager.cpp
	$(CC) $(C_FLAGS) -c game_manager.cpp

property.o: property.cpp
	$(CC) $(C_FLAGS) -c property.cpp

tenant.o: tenant.cpp
	$(CC) $(C_FLAGS) -c tenant.cpp

clean:
	$(RM) apartment_complex.o business_complex.o business.o citizen.o driver.o game_manager.o property.o tenant.o *.out $(exe) *.gch peda*

compress:
	tar zcvf assign3.tar.gz Makefile helper.* apartment_complex.?pp business_complex.?pp business.?pp citizen.?pp game_manager.?pp list.?pp property.?pp tenant.?pp driver.?pp
