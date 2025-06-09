# Makefile for the UnTar project

# Compiler and flags
CC     = gcc

# Project name
NAME   = untar

# Sources and objects
SRCS   = main.c src/getters.c src/process.c src/utils.c
OBJS   = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Link object files into the final executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything including the executable
fclean: clean
	rm -f $(NAME)

# Clean and re-make
re: fclean all

.PHONY: all clean fclean re

