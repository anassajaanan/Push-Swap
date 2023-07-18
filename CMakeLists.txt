cmake_minimum_required(VERSION 3.25)
project(push C)

set(CMAKE_C_STANDARD 11)

add_executable(push include/push_swap.h lib/ft_split.c src/args.c src/push_swap_utils.c src/stack.c src/stack_operations_a.c src/stack_operations_b.c sorting_algorithms/quick_sort.c sorting_algorithms/cost_sort.c src/push_swap.c sorting_algorithms/small_sort.c sorting_algorithms/cost_sort_utils.c src/checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c include/checker.h src/checker_utils.c lib/ft_strcmp.c lib/ft_atoi.c lib/is_numeric.c)
