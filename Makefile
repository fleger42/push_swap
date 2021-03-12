PUSH_NAME = push_swap

CHECKER_NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libft -lft

PUSH_HEADER = -I push_swap_dir/includes -I libft/

CHECK_HEADER = -I checker_dir/ -I libft/

PUSH_SRC = push_swap.c ft_struct_push.c ft_verif.c  ft_t_pile_utils.c \
			ft_t_pile.c 

CHECK_SRC = checker.c

PUSH_SRCS = $(addprefix push_swap_dir/srcs/, $(PUSH_SRC))
	
CHECKER_SRCS = $(addprefix checker_dir/, $(CHECK_SRC))

PUSH_OBJ = $(PUSH_SRCS:c=o)

CHECKER_OBJ = $(CHECKER_SRCS:c=o)

all: $(PUSH_NAME) $(CHECKER_NAME)

$(PUSH_NAME): $(PUSH_OBJ)
	@echo "\n"
	@make -C libft/
	@echo "\033[0;32mCompiling pushswap..."
	$(CC) $(CFLAGS) -o $(PUSH_NAME) $(PUSH_OBJ) $(LIBFT)
	@echo "\n\033[0mDone !"

$(CHECKER_NAME): $(CHECKER_OBJ)
	@echo "\n"
	@make -C libft/
	@echo "\033[0;32mCompiling checker..."
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJ) $(LIBFT)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} $(LIBFT) $(PUSH_HEADER) $(CHECK_HEADER) -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(PUSH_OBJ) $(CHECKER_OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(PUSH_OBJ) $(CHECKER_OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(PUSH_NAME) $(CHECKER_NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re test norm
