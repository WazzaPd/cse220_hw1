# Define the compiler and flags
CC = gcc
CFLAGS = -Wall

# Define the source files and object files
SRC = hw1_game.c hw1.c 
OBJ = hw1_game.o hw1.o 

# Target executable
TARGET = myprogram

# Default target: Compile and link all in one step
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(TARGET)
