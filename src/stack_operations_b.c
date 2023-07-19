/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:23:53 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 16:21:50 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	ft_sb(t_stack *s, int print_flag)
{
	int	temp;

	if (s->top && s->top->next)
	{
		temp = s->top->val;
		s->top->val = s->top->next->val;
		s->top->next->val = temp;
	}
	if (print_flag)
		ft_putstr("sb\n");
}

void	ft_pb(t_stack *a, t_stack *b, int print_flag)
{
	if (a->top)
		push(b, pop(a));
	if (print_flag)
		ft_putstr("pb\n");
}

void	ft_rb(t_stack *b, int print_flag)
{
	struct s_stack_node	*temp;

	if (b->top && b->top->next)
	{
		temp = b->top;
		b->top = b->top->next;
		b->last->next = temp;
		temp->prev = b->last;
		b->last = temp;
		b->top->prev = NULL;
		b->last->next = NULL;
	}
	if (print_flag)
		ft_putstr("rb\n");
}

void	ft_rrb(t_stack *b, int print_flag)
{
	struct s_stack_node	*temp;

	if (b->top && b->top->next)
	{
		temp = b->last;
		b->last = b->last->prev;
		b->top->prev = temp;
		temp->next = b->top;
		b->top = temp;
		b->last->next = NULL;
		b->top->prev = NULL;
	}
	if (print_flag)
		ft_putstr("rrb\n");
}
