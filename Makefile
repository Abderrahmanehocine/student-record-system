# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data

# Files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/student.c $(SRC_DIR)/file_handler.c $(SRC_DIR)/menu.c
OBJS = $(SRCS:.c=.o)
TARGET = student_record_system

# Default rule
all: $(TARGET)

# Link all object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile source files to object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
