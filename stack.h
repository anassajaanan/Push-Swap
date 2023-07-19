/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:47:34 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 09:23:39 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_STACK_H
#define PUSH_STACK_H

# include <stdlib.h>
#include "lib.h"

/* ================ Stack ================ */
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

/* ================ Stack_Str ================ */
struct s_stack_node_str
{
	char                    *val;
	struct s_stack_node_str	*next;
};

typedef struct s_stack_str
{
	struct s_stack_node_str	*top;
}						t_stack_str;

/* ================ Stack ================ */
void	init_stack(t_stack *s);
int	    stack_is_empty(t_stack *s);
void	push(t_stack *s, int val);
int	    pop(t_stack *s);
void    free_stack(t_stack *s);

/* ================ Stack_Str ================ */
void	init_stack_str(t_stack_str *s);
void	push_str(t_stack_str *s, char *val);
char    *pop_str(t_stack_str *s);
void    free_stack_str(t_stack_str *s);


/* ================ stack_operations_a ================ */
void	ft_sa(t_stack *s, int print_flag);
void	ft_pa(t_stack *a, t_stack *b, int print_flag);
void	ft_ra(t_stack *a, int print_flag);
void	ft_rra(t_stack *a, int print_flag);

/* ================ stack_operations_b ================ */
void	ft_sb(t_stack *s, int print_flag);
void	ft_pb(t_stack *a, t_stack *b, int print_flag);
void	ft_rb(t_stack *b, int print_flag);
void	ft_rrb(t_stack *b, int print_flag);

#endif //PUSH_STACK_H
