NAME = push_swap

SRCS = src/args.c src/push_swap.c src/push_swap_utils.c src/stack.c src/stack_operations_a.c \
		src/stack_operations_b.c src/stack_str.c \
		sorting_algorithms/cost_sort.c sorting_algorithms/cost_sort_utils.c sorting_algorithms/quick_sort.c \
		sorting_algorithms/small_sort.c\
		lib/ft_atoi.c lib/ft_putstr.c lib/ft_split.c lib/ft_strcmp.c lib/ft_strdup.c lib/ft_strlcpy.c \
		lib/ft_strlen.c lib/get_next_line.c lib/get_next_line_utils.c lib/is_numeric.c

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ./include

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

${NAME} : ${OBJS}
		${CC} ${CFLAGS} -o $@ $^

%.o:	%.c
		${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re