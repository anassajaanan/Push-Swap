/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:49:12 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 16:49:17 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_CHECKER_H
#define PUSH_CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
void        handle_arguments(int argc, char *argv[], int *size, char ***args);
t_stack	    *get_validated_stack(int size, char **args);

//  utils.c
void	display_stack(t_stack *a);
int	    get_min(t_stack s);
int     get_max(t_stack s);
int	    is_stack_sorted(t_stack *s);


// lib
char	    **ft_split(const char *str, char sep);
int	        ft_strcmp(const char *s1, const char *s2);
long int	ft_atoi(const char *str);
int	        is_numeric(const char *str);

int is_valid_instruction(char *str);
void    execute_instruction(t_stack *a, t_stack *b, char *str);
void    execute_instruction2(t_stack *a, t_stack *b, char *str);
void	free_args(char **args);

#endif //PUSH_CHECKER_H
