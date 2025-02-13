# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 09:27:07 by mait-you          #+#    #+#              #
#    Updated: 2025/02/13 10:44:08 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compiler and Flags
CC          := cc
CFLAGS      := #-Wall -Wextra -Werror
MLX_DIR     := mlx_linux
MLX_FLAGS   := -I$(MLX_DIR) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES    := -I. -I$(MLX_DIR)
RM          := rm -rf
AR          := ar rcs

### dirs
SRC_DIR		:= mandatory/srcs
OBJS_DIR	:= obj

### Executable Name
NAME		:= so_long

### Source Files
SRCS		:= $(SRC_DIR)/so_long.c 

### Object Files
OBJS		:= $(SRCS:%.c = $(OBJS_DIR)/%.o)

### Colors and Formatting
RESET		:= \033[0m
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
PURPLE		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m
BOLD		:= \033[1m
UP			:= \033[F

### Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
#@echo "$(RED)$(BOLD)$(NAME) $(GREEN)compiled successfully!$(RESET)"

$(OBJS_DIR)/mandatory/%.o: $(SRC_DIR)/%.c mandatory/so_long.h | $(OBJS_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS_DIR)
#@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	$(RM) $(NAME)
#@echo "$(RED)$(UP)Cleaned object files and $(RED)$(BOLD)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re

#git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
#cd mlx_linux
#make
#cd ..