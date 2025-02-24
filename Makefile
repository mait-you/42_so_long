# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 18:30:46 by mait-you          #+#    #+#              #
#    Updated: 2025/02/24 19:58:40 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### dirs
SRC_DIR		:= srcs
SRC_UTL		:= utils
SRC_ANM		:= utils/animation
SRC_CLN		:= utils/cleanup
SRC_IMG		:= utils/imgs_init
SRC_MAP		:= utils/map_init
SRC_MEM		:= utils/mem_init
LIBFT_DIR	:= libft
OBJS_DIR	:= obj

### Compiler and Flags
CC			:= cc
AR			:= ar rsc
CFLAGS		:= -Wall -Wextra -Werror -Imlx -fsanitize=address -g
INCLUDES	:= -lmlx -framework OpenGL -framework AppKit
RM			:= rm -rf

### Executable Name
NAME		:= so_long
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_LIB		:= $(MLX_DIR)/libmlx.a

### Source Files
LIBFT_SRCS	:= $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_memcmp.c \
			$(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr.c \
			$(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strcspn.c \
			$(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strncmp.c \
			$(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/get_next_line.c

SRCS		:= $(SRC_DIR)/so_long.c $(SRC_UTL)/so_long_utils.c $(SRC_ANM)/animation.c $(SRC_CLN)/cleanup.c \
			$(SRC_CLN)/destroy_images.c $(SRC_IMG)/img_game_obj_init.c $(SRC_IMG)/img_player_init.c \
			$(SRC_MAP)/flood_fill_chek.c $(SRC_MAP)/get_map.c $(SRC_MAP)/load_map.c $(SRC_MAP)/texturnbr.c \
			$(SRC_MEM)/game_initialize.c 

OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)
LIBFT_OBJS	:= $(LIBFT_SRCS:%.c=$(OBJS_DIR)/%.o)

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

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) $(GREEN)compiled successfully!$(RESET)"

$(LIBFT): $(LIBFT_OBJS)
	@$(AR) $(LIBFT) $(LIBFT_OBJS)
	@echo "$(CYAN)Building libft ...$(RESET)"
	@echo "$(CYAN)╚═ Built $(PURPLE)$(BOLD)$(LIBFT)$(RESET)"

# libft $(LIB_DIR) Object file compilation rules
$(OBJS_DIR)/$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

# so_long Object file compilation rules
$(OBJS_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c so_long.h $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

# so_long utils Object file compilation rules
$(OBJS_DIR)/$(SRC_UTL)/%.o: $(SRC_UTL)/%.c so_long.h $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) $(OBJS_DIR) $(LIBFT)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(UP)Cleaned object files and $(RED)$(BOLD)$(NAME)$(RESET)"

re: fclean all

.PHONY: clean