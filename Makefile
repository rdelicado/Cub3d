# --- Colors ---

BOLD      := \033[1m
BLACK     := \033[30;1m
RED       := \033[31;1m
GREEN     := \033[32;1m
YELLOW    := \033[33;1m
BLUE      := \033[34;1m
MAGENTA   := \033[35;1m
CYAN      := \033[36;1m
WHITE     := \033[37;1m
RESET     := \033[0m

# --- Name & flags ---
CC		= gcc
NAME	= cub3d
CFLAGS	= -g -Wall -Werror -Wextra

# --- Library ---

LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS = -L $(LIBMLX) -lmlx42 -ldl -lm -lglfw           
endif
ifeq ($(UNAME_S),Darwin)
	LIBS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a
endif

# --- Files ---

SRCS	= 	utils_player.c move_player.c\
			main.c \
			ft_windows.c raycast.c utils_raycast.c\
			init_structs.c\
			textures.c\
			000libft1.c 001split.c 002lists.c 100check.c 101-1checkLimits.c \
			101-2checkLimits.c 102-1checkContentFile.c 102-2checkContentFile.c 102-3checkContentFile.c 110initialize.c \
			120errorMessages.c 200gnl.c 210gnlUtils.c 999free.c 101-3checkLimits.c\
			
OBJS	= $(addprefix obj/,$(SRCS:.c=.o))
DEBUG	= -fsanitize=address

# --- Rules ---

all: libmlx $(NAME)

create_dir:
	@mkdir -p obj

vpath %.c src src/parseo src/main src/player src/raycasting

libmlx:
	@$(MAKE) -C $(LIBMLX)

$(OBJS) : obj/%.o: %.c | create_dir
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(BOLD)Compiling Cub3d...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"
	@sleep 1
	@clear

clean:
	@echo "$(RED)$(BOLD)Cleaning objects from program...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"
	@sleep 1
#	@clear
	

fclean: clean
	@echo "$(RED)$(BOLD)Cleaning all files from program...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"
	@sleep 1
	@clear

re: clean all

norma:
	@echo "$(BLUE)$(BOLD)Checking norminette...$(RESET)"
	@norminette src/* include/*

.PHONY: all, clean, fclean, re, norma, libmlx, bonus