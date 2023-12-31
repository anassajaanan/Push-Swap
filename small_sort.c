/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:33:17 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 15:03:02 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a)
{
	int	max;

	if (a->length <= 1)
		return ;
	else if (a->length == 2)
	{
		if (a->top->val > a->top->next->val)
			ft_sa(a, 1);
	}
	else if (a->length == 3)
	{
		max = get_max(*a);
		if (a->top->val == max)
			ft_ra(a, 1);
		else if (a->top->next->val == max)
			ft_rra(a, 1);
		if (a->top->val > a->top->next->val)
			ft_sa(a, 1);
	}
}
