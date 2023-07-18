/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:49:18 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 15:31:41 by aajaanan         ###   ########.fr       */
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
#include "../include/string_stack.h"

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
void	ft_sa(t_stack *s, int print_flag);
void	ft_pa(t_stack *a, t_stack *b, int print_flag);
void	ft_ra(t_stack *a, int print_flag);
void	ft_rra(t_stack *a, int print_flag);

// stack_operations_b.c
void	ft_sb(t_stack *s, int print_flag);
void	ft_pb(t_stack *a, t_stack *b, int print_flag);
void	ft_rb(t_stack *b, int print_flag);
void	ft_rrb(t_stack *b, int print_flag);

// args.c
int	        has_duplicates(t_stack *s);
//void        handle_arguments(int argc, char *argv[], int *size, char ***args);
//void        create_validated_stack(int size, char **args, t_stack *a, int *is_valid);
//t_stack     *get_validated_stack(int size, char **args);
t_stack_str *parse_arguments(int argc, char *argv[]);
void    create_validated_stack(t_stack *a, t_stack_str *args, int *is_valid);
t_stack     *get_validated_stack(int argc, char *argv[]);


//  utils.c
void	display_stack(t_stack *a);
int	    get_min(t_stack s);
int     get_max(t_stack s);
int	    is_stack_sorted(t_stack *s);
void	free_args(char **args);


// Small Sort
void    sort_small(t_stack *a);

// Quick Sort
void	merge(int A[], int l, int mid, int h);
void	merge_sort(int A[], int low, int high);
void    stack_to_array(int *array, t_stack *a);
int     get_pivot(t_stack *a);
void    quick_sort(t_stack *a, t_stack *b);

// Cost Sort
int                 get_top_cost(t_stack *s, int val);
void                move_min_to_top(t_stack *a);
int                 find_best_target_in_stack_a(t_stack *a, int src_value_b);
struct s_min_cost   *find_min_cost_b(t_stack *a, t_stack *b);
void                cost_sort(t_stack *a, t_stack *b);

// Cost Sort Utils
void    rotate_stack_a(t_stack *a, int cost);
void    rotate_stack_b(t_stack *b, int cost);



#endif //PUSH_SWAP_H