/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:38:32 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 15:01:09 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_stack_a(t_stack *a, int cost)
{
	int	i;

	i = 0;
	if (cost >= 0)
	{
		while (i < cost)
		{
			ft_ra(a);
			i++;
		}
	}
	else
	{
		while (i < abs(cost))
		{
			ft_rra(a);
			i++;
		}
	}
}

void	rotate_stack_b(t_stack *b, int cost)
{
	int	i;

	i = 0;
	if (cost >= 0)
	{
		while (i < cost)
		{
			ft_rb(b);
			i++;
		}
	}
	else
	{
		while (i < abs(cost))
		{
			ft_rrb(b);
			i++;
		}
	}
}
