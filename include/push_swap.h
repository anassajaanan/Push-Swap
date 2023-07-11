/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:49:18 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/24 14:42:38 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:29:02 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/12 16:29:02 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

struct s_stack_node
{
    struct s_stack_node	*prev;
    int					val;
    struct s_stack_node	*next;
};

typedef struct s_stack
{
    struct s_stack_node	*top;
    struct s_stack_node	*last;
    int					length;
}						t_stack;

struct s_min_cost
{
	int src_cost;
	int target_cost;
};

// stack.c
void	init_stack(t_stack *s);
int	    stack_is_empty(t_stack *s);
void	push(t_stack *s, int val);
int	    pop(t_stack *s);
void    free_stack(t_stack *s);


// stack_operations_a.c
void    ft_sa(t_stack *s);
void    ft_pa(t_stack *a, t_stack *b);
void    ft_ra(t_stack *a);
void    ft_rra(t_stack *a);

// stack_operations_b.c
void    ft_sb(t_stack *s);
void    ft_pb(t_stack *a, t_stack *b);
void    ft_rb(t_stack *b);
void    ft_rrb(t_stack *b);

// args.c
int	        is_numeric(const char *str);
long int	ft_atoi(const char *str);
int	        has_duplicates(t_stack *s);
void        handle_arguments(int argc, char *argv[], int *size, char ***args);
t_stack	    *get_validated_stack(int size, char **args);

//  utils.c
void	display_stack(t_stack *a);
int	    get_min(t_stack s);
int     get_max(t_stack s);
int	    is_a_sorted(t_stack *s);
int     is_b_sorted(t_stack *s);
int	    is_stack_sorted(t_stack *s);


// ft_split
static int	is_separator(char c, char sep);
static int	count_words(const char *str, char sep);
static void	copy_word(char *dest, const char *src, char sep);
static void	add_words(char **array, const char *str, char sep);
char	    **ft_split(const char *str, char sep);


//// quick_sort.c
//void        quick_sort_stacks(t_stack *a, t_stack *b);
//void        sort_two_elements(t_stack *a);
//void        sort_three_elements(t_stack *a);
//void        partition_elements(t_stack *a, t_stack *b, int pivot, int length);
//void        insert_elements(t_stack *a, t_stack *b, int *array, int length);
//
//// quick_sort_utils.c
//void        swap(int *a, int *b);
//void	    bubble_sort(int A[], int size);
//void        stack_to_array(int *array, t_stack *stack);
//int         get_pivot(int *array, int length);

//// radix_sort.c
//void        radix_sort_stacks(t_stack *a, t_stack *b);
//void        process_radix_bits(t_stack *a, t_stack *b, int max_bits);
//void        process_stack_a(t_stack *a, t_stack *b, int bit_position, int len, int *stop);
//void        process_stack_b(t_stack *a, t_stack *b, int bit_position, int len, int *stop);
//
//// radix_sort_utils.c
//int         count_bits(int max_num);
//int         all_bits_zero(t_stack *stack, int bit_position);
//int         all_bits_one(t_stack *stack, int bit_position);
//void        adjust_values(t_stack *stack, int min_value);
//void        restore_values(t_stack *stack, int min_value);

#endif //PUSH_SWAP_H