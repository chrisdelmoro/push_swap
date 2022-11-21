NAME			= push_swap
NAME_BONUS		= push_swap_bonus

LIBFT_DIR		= ./libs/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

HEADER_DIR		= ./include/
HEADER			= push_swap.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

SRC_DIR			= ./src/
SRC				= 	push_swap.c \
					param_validation.c \
					dlist_utils.c \
					stack_utils_swap.c \
					stack_utils_push.c \
					stack_utils_rotate.c \
					stack_utils_rev_rotate.c \
					stack_initialization.c \
					sort_stack.c \
					sort_small.c \
					sort_big_hundred.c \
					sort_big_five_hundred.c \
					sort_big_utils.c
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH) $(HEADER_PATH)
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

re: fclean all

.PHONY: all clean fclean re
