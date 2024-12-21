# Compiler and flags
CC = clang
CFLAGS = -Wall -Wvla -Werror -g

# Directories
SRC_DIR = src
INC_DIR = include

# Source and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/hash.c
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = passcracker

# Build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $(OBJS)

# Compile source files into object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: clean
