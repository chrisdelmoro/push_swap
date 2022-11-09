NAME			= push_swap
NAME_BONUS		= push_swap_bonus

LIBFT_DIR		= ./libs/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

HEADER_DIR		= ./include/
HEADER			= push_swap.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR_BONUS	= ./bonus/include/
HEADER_BONUS		= push_swap_bonus.h
HEADER_PATH			= $(addprefix $(HEADER_DIR_BONUS), $(HEADER_BONUS))

SRC_DIR			= ./src/
SRC				= 	push_swap.c \
					param_validation.c \
					dlist_utils.c \
					dlist_utils_2.c \
					stack_utils_swap.c \
					stack_utils_push.c \
					stack_utils_rotate.c \
					stack_utils_rev_rotate.c \
					stack_initialization.c \
					sort_stack.c
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

SRC_DIR_BONUS	= ./bonus/src/
SRC_BONUS		= push_swap_bonus.c
SRC_PATH_BONUS	= $(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

BIN_BONUS			= ./bonus/bin/
BINARY_OUT_BONUS	= $(addprefix $(BIN_BONUS), $(NAME_BONUS))

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

clean:
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ echo "libft object files erased successfully!"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "$(NAME) binaries erased successfully!"
	@ rm -f $(BINARY_OUT_BONUS)
	@ rm -rf $(BIN_BONUS)
	@ echo "$(NAME_BONUS) binaries erased successfully!"

bonus: $(BINARY_OUT_BONUS)

$(BINARY_OUT_BONUS): $(SRC_PATH_BONUS)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_BONUS)
	@ mv $(NAME_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_BONUS) compiled successfully!"

valgrind:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -g -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

valgrind_bonus:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -g -o $(NAME_BONUS)
	@ mv $(NAME_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_BONUS) compiled successfully!"

re: fclean all

.PHONY: all clean fclean re
