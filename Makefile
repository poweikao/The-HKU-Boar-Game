CC= g++
CFLAGS= -Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter -Wno-sign-compare
EXEC= main.exe

SRC= main.cpp printer.cpp minesweeper.cpp snake.cpp pushbox.cpp
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

deep_clean:
	rm -f *.o *.exe

.PHONY: clean deep_clean