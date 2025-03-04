# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 18:30:46 by mait-you          #+#    #+#              #
#    Updated: 2025/03/03 15:51:20 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### dirs
SRC_DIR		:= mandatory/srcs
SRC_UTL		:= mandatory/utils
SRC_CLN		:= mandatory/cleanup
SRC_IMG		:= mandatory/images_init
SRC_MAP		:= mandatory/map_init
SRC_MEM		:= mandatory/mem_init

SRC_DIR_B	:= bonus/srcs_bonus
SRC_UTL_B	:= bonus/utils_bonus
SRC_ANM_B	:= bonus/animation_bonus
SRC_CLN_B	:= bonus/cleanup_bonus
SRC_IMG_B	:= bonus/images_init_bonus
SRC_MAP_B	:= bonus/map_init_bonus
SRC_MEM_B	:= bonus/mem_init_bonus
LIBFT_DIR	:= libft
OBJS_DIR	:= obj

### Compiler and Flags
CC			:= cc
AR			:= ar rsc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDES	:= -lmlx -framework OpenGL -framework AppKit
RM			:= rm -rf

### Executable Name
NAME		:= so_long
BONUS		:= so_long_bonus
LIBFT		:= $(LIBFT_DIR)/libft.a

### Source Files
LIBFT_SRCS	:= $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_abs.c \
			$(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr.c \
			$(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strcspn.c \
			$(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strncmp.c \
			$(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/get_next_line.c 

BONUS_SRCS	:= $(SRC_DIR_B)/so_long_bonus.c $(SRC_UTL_B)/so_long_utils_bonus.c $(SRC_UTL_B)/so_long_utils_bonus_1.c \
			$(SRC_ANM_B)/animation_bonus.c $(SRC_ANM_B)/animation_enemy.c $(SRC_CLN_B)/cleanup_bonus.c $(SRC_CLN_B)/destroy_images_bonus.c \
			$(SRC_IMG_B)/images_game_obj_init_bonus.c $(SRC_IMG_B)/images_player_init_bonus.c $(SRC_MAP_B)/flood_fill_chek_bonus.c \
			$(SRC_MAP_B)/get_map_bonus.c $(SRC_MAP_B)/load_map_bonus.c $(SRC_MAP_B)/texturnbr_bonus.c $(SRC_MEM_B)/game_initialize_bonus.c 

SRCS		:= $(SRC_DIR)/so_long.c $(SRC_UTL)/so_long_utils.c $(SRC_CLN)/cleanup.c $(SRC_CLN)/destroy_images.c \
			$(SRC_IMG)/images_init.c $(SRC_MAP)/flood_fill_chek.c $(SRC_MAP)/get_map.c $(SRC_MAP)/load_map.c \
			$(SRC_MEM)/game_initialize.c 

OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)
LIBFT_OBJS	:= $(LIBFT_SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	:= $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

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
	@echo "$(RED)$(BOLD)$(NAME) $(GREEN)Compiled successfully!$(RESET)"

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
$(OBJS_DIR)/mandatory/%.o: mandatory/%.c mandatory/so_long.h $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(INCLUDES) -o $(BONUS)
	@echo "$(RED)$(BOLD)$(BONUS) $(GREEN)Compiled successfully!$(RESET)"

# so_long_bonus Object file compilation rules
$(OBJS_DIR)/bonus/%.o: bonus/%.c bonus/so_long_bonus.h $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) $(OBJS_DIR) $(LIBFT)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(RED)$(UP)Cleaned object files and $(RED)$(BOLD)$(NAME)$(RESET)"

re: fclean all

.PHONY: clean