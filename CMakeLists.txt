cmake_minimum_required(VERSION 3.25)
project(push C)

set(CMAKE_C_STANDARD 11)

add_executable(push include/push_swap.h lib/ft_split.c src/args.c src/push_swap.c src/push_swap_utils.c src/quick_sort.c src/quick_sort_utils.c src/radix_sort.c src/radix_sort_utils.c src/stack.c src/stack_operations_a.c src/stack_operations_b.c)
