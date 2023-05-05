CC= g++
CXXFLAGS=-I local/include/ncursestw -I local/lib -I local/include -I include -pthread -std=c++11 -pedantic-errors
LDFLAGS=-I local/include/ncursestw -L local/lib -std=c++11 -pedantic-errors -lncursesw -fstack-protector

# The output executable name
EXEC= THE_HKU_BOAR_GAME

# Source files
SRC= main.cpp plot.cpp minesweeper.cpp snake.cpp pushbox.cpp
# Object files generated from source files
OBJ= $(SRC:.cpp=.o)

# Targets

# Default target: Build the executable
all: $(EXEC)
	echo "Compile Done."

# Link object files into the executable
$(EXEC): ncurses $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Compile ncurses
ncurses:
	chmod +x buildncurses.sh
	./buildncurses.sh

# Remove object files and the executable
clean:
	rm -f *.o
	rm $(EXEC)
	rm game_log.txt

# Remove object files, the executable, ncurses, and local directories
deep_clean:
	rm -f *.o *.exe
	rm -rfv ncurses
	rm -rfv local
	rm $(EXEC)
	rm game_log.txt

# Phony targets (not associated with files)
.PHONY: ncurses clean deep_clean