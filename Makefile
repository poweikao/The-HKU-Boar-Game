CC= g++
CFLAGS= -Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter
EXEC= main.exe

SRC= main.cpp printer.cpp minesweeper.cpp snake.cpp solitare.cpp
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

.PHONY: clean