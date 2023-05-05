CC= g++
CFLAGS= -Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter -Wno-sign-compare -I local/include/ncursestw -I local/include -I include -pthread -Ofast
LDFLAGS=-L local/lib -std=c++11 -pedantic-errors -lncursestw -ldl -pthread
EXEC= main.exe

SRC= main.cpp printer.cpp minesweeper.cpp snake.cpp pushbox.cpp
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): ncurses $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compile ncurses
ncurses:
	chmod +x buildncurses.sh
	./buildncurses.sh

clean:
	rm -f *.o

deep_clean:
	rm -f *.o *.exe

.PHONY: ncurses clean deep_clean