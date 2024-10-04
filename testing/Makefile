# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 15:27:08 by yustinov          #+#    #+#              #
#    Updated: 2024/10/04 15:32:18 by yustinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Executable names
NAME_SIMPLE = gnl_test
NAME_BONUS = gnl_bonus_test

# Source files for simple and bonus parts
SRC_SIMPLE = ../get_next_line.c ../get_next_line_utils.c
SRC_BONUS = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c

# Test files for simple and bonus parts
TEST_SIMPLE = main.c
TEST_BONUS = main_bonus.c

# Object files for simple and bonus parts
OBJ_SIMPLE = $(SRC_SIMPLE:.c=.o) $(TEST_SIMPLE:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o) $(TEST_BONUS:.c=.o)

# Include directories
INCLUDE = -I..

# Default target
all: $(NAME_SIMPLE)

# Compile simple part
$(NAME_SIMPLE): $(OBJ_SIMPLE)
	$(CC) $(CFLAGS) -o $@ $^

# Compile bonus part
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rules for compiling .c files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f $(OBJ_SIMPLE) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME_SIMPLE) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re

