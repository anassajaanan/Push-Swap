/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:36:20 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 15:00:41 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_top_cost(t_stack *s, int val)
{
	int					i;
	struct s_stack_node	*temp;

	temp = s->top;
	i = 0;
	while (temp && temp->val != val)
	{
		temp = temp->next;
		i++;
	}
	if (i <= s->length / 2)
		return (i);
	else
		return (-(s->length - i));
}

void	move_min_to_top(t_stack *a)
{
	int	i;
	int	min;
	int	instructions;

	i = 0;
	min = get_min(*a);
	instructions = get_top_cost(a, min);
	if (instructions >= 0)
	{
		while (i < instructions)
		{
			ft_ra(a, 1);
			i++;
		}
	}
	else
	{
		while (i < abs(instructions))
		{
			ft_rra(a, 1);
			i++;
		}
	}
}

int	find_best_target_in_stack_a(t_stack *a, int src_value_b)
{
	t_stack				*s;
	int                 target;
	struct s_stack_node	*temp;

	s = (t_stack *)malloc(sizeof(t_stack));
	init_stack(s);
	temp = a->top;
	while (temp)
	{
		if (temp->val > src_value_b)
			push(s, temp->val);
		temp = temp->next;
	}
	if (s->length == 0)
		target = get_min(*a);
	else
		target = get_min(*s);
	free_stack(s);
	return (target);
}

struct s_min_cost	*find_min_cost_b(t_stack *a, t_stack *b)
{
	int					min_cost;
	int					src_cost;
	int					target_cost;
	struct s_stack_node	*temp;
	struct s_min_cost	*min_cost_data;

	min_cost = INT_MAX;
	temp = b->top;
	min_cost_data = (struct s_min_cost *)malloc(sizeof(struct s_min_cost));
	while (temp)
	{
		src_cost = get_top_cost(b, temp->val);
		target_cost = 
			get_top_cost(a, find_best_target_in_stack_a(a, temp->val));
		if (abs(src_cost) + abs(target_cost) < min_cost)
		{
			min_cost_data->src_cost = src_cost;
			min_cost_data->target_cost = target_cost;
			min_cost = abs(src_cost) + abs(target_cost);
		}
		temp = temp->next;
	}
	return (min_cost_data);
}

void	cost_sort(t_stack *a, t_stack *b)
{
	struct s_min_cost	*min_cost_data;

	while (b->top)
	{
		min_cost_data = find_min_cost_b(a, b);
		rotate_stack_a(a, min_cost_data->target_cost);
		rotate_stack_b(b, min_cost_data->src_cost);
		free(min_cost_data);
		ft_pa(a, b, 1);
	}
	move_min_to_top(a);
}
