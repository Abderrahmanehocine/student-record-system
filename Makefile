# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -I$(INCLUDE_DIR)

# Directories
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Target binary name
TARGET = student_record_system

# Default rule
all: $(TARGET)

# Link object files into final binary
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile each .c file to .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/*.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and binary
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
