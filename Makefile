PUSH_NAME = push_swap

CHECKER_NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libft

PUSH_HEADER = push_swap_dir/push_swap.h

CHECK_HEADER = checker_dir/checker.h

PUSH_SRC = push_swap.c

CHECK_SRC = checker.c

PUSH_SRCS = $(addprefix push_swap_dir/, $(PUSH_SRC))
	
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
	@${CC} ${CFLAGS} -c $< -o $@

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
