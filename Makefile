NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	main.c\
		checks.c\
		utils_exit.c\
		utils_libft.c\
		utils_stack.c\
		op_push.c\
		op_reverse.c\
		op_reverse_rotate.c\
		op_swap.c\
		stack.c\
		alg_cost.c\
		alg_move.c\
		alg_position.c\
		sort.c\

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all