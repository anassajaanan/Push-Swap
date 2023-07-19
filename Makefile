NAME =			push_swap

BONUS_NAME =	checker

SRCS =			args.c push_swap.c push_swap_utils.c stack.c stack_operations_a.c stack_operations_b.c stack_str.c \
				cost_sort.c cost_sort_utils.c quick_sort.c small_sort.c\
				ft_atoi.c ft_putstr_fd.c ft_split.c ft_strcmp.c ft_strdup.c ft_strlcpy.c ft_strlen.c get_next_line.c get_next_line_utils.c is_numeric.c

BONUS_SRCS =	args.c checker.c checker_utils.c stack.c stack_operations_a.c stack_operations_b.c stack_str.c \
				quick_sort.c \
				ft_atoi.c ft_putstr_fd.c ft_split.c ft_strcmp.c ft_strdup.c ft_strlcpy.c ft_strlen.c get_next_line.c get_next_line_utils.c is_numeric.c

OBJS =			$(SRCS:.c=.o)

BONUS_OBJS =	$(BONUS_SRCS:.c=.o)

INCLUDE_DIR =	./

CC =			cc

CFLAGS =		-Wall -Wextra -Werror

RM =			rm -fr

${NAME}:		${OBJS}
				${CC} ${CFLAGS} -o $@ $^

bonus:			${BONUS_OBJS}
				${CC} ${CFLAGS} -o ${BONUS_NAME} $^

%.o:			%.c
				${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

all:			${NAME}

clean:
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:			clean
				${RM} ${NAME} ${BONUS_NAME}

re:				fclean all

.PHONY:			all clean fclean re