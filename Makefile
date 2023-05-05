CC= g++
CXXFLAGS=-I local/include/ncursestw -I local/lib -I local/include -I include -pthread -std=c++11 -pedantic-errors
LDFLAGS=-I local/include/ncursestw -L local/lib -std=c++11 -pedantic-errors -lncursesw -fstack-protector
EXEC= THE_HKU_BOAR_GAME

SRC= main.cpp plot.cpp minesweeper.cpp snake.cpp pushbox.cpp
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)
	echo "Compile Done."

$(EXEC): ncurses $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compile ncurses
ncurses:
	chmod +x buildncurses.sh
	./buildncurses.sh

clean:
	rm -f *.o
	rm  $(EXEC)

deep_clean:
	rm -f *.o *.exe
	rm -rfv ncurses
	rm -rfv local

.PHONY: ncurses clean deep_clean