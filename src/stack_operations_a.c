/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:23:53 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 19:06:55 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:23:53 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 16:20:20 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stack *s, int print_flag)
{
	int	temp;

	if (s->top && s->top->next)
	{
		temp = s->top->val;
		s->top->val = s->top->next->val;
		s->top->next->val = temp;
	}
	if (print_flag)
		printf("sa\n");
}

void	ft_pa(t_stack *a, t_stack *b, int print_flag)
{
	if (b->top)
		push(a, pop(b));
	if (print_flag)
		printf("pa\n");
}

void	ft_ra(t_stack *a, int print_flag)
{
	struct s_stack_node	*temp;

	if (a->top && a->top->next)
	{
		temp = a->top;
		a->top = a->top->next;
		a->last->next = temp;
		temp->prev = a->last;
		a->last = temp;
		a->last->next = NULL;
		a->top->prev = NULL;
	}
	if (print_flag)
		printf("ra\n");
}

void	ft_rra(t_stack *a, int print_flag)
{
	struct s_stack_node	*temp;

	if (a->top && a->top->next)
	{
		temp = a->last;
		a->last = a->last->prev;
		a->top->prev = temp;
		temp->next = a->top;
		a->top = temp;
		a->last->next = NULL;
		a->top->prev = NULL;
	}
	if (print_flag)
		printf("rra\n");
}
