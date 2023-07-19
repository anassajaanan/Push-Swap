NAME = push_swap

BONUS_NAME = checker

SRCS = src/args.c src/push_swap.c src/push_swap_utils.c src/stack.c src/stack_operations_a.c \
		src/stack_operations_b.c src/stack_str.c \
		sorting_algorithms/cost_sort.c sorting_algorithms/cost_sort_utils.c sorting_algorithms/quick_sort.c \
		sorting_algorithms/small_sort.c\
		lib/ft_atoi.c lib/ft_putstr_fd.c lib/ft_split.c lib/ft_strcmp.c lib/ft_strdup.c lib/ft_strlcpy.c \
		lib/ft_strlen.c lib/get_next_line.c lib/get_next_line_utils.c lib/is_numeric.c

BONUS_SRCS = src/args.c src/checker.c src/checker_utils.c src/stack.c \
			src/stack_operations_a.c src/stack_operations_b.c src/stack_str.c \
			sorting_algorithms/quick_sort.c \
			lib/ft_atoi.c lib/ft_putstr_fd.c lib/ft_split.c lib/ft_strcmp.c lib/ft_strdup.c lib/ft_strlcpy.c \
			lib/ft_strlen.c lib/get_next_line.c lib/get_next_line_utils.c lib/is_numeric.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

INCLUDE_DIR = ./include

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

${NAME}: ${OBJS}
		${CC} ${CFLAGS} -o $@ $^

bonus:	${BONUS_OBJS}
		${CC} ${CFLAGS} -o ${BONUS_NAME} $^

%.o:	%.c
		${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

all:	${NAME}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME} ${BONUS_NAME}

re:		fclean all

.PHONY:	all clean fclean re