/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:45:18 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 14:10:33 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack s)
{
	struct s_stack_node	*p;
	int					min;

	min = 2147483647;
	p = s.top;
	while (p)
	{
		if (p->val < min)
			min = p->val;
		p = p->next;
	}
	return (min);
}

int	get_max(t_stack s)
{
	struct s_stack_node	*p;
	int					max;

	max = -2147483648;
	p = s.top;
	while (p)
	{
		if (p->val > max)
			max = p->val;
		p = p->next;
	}
	return (max);
}

int	is_stack_sorted(t_stack *s)
{
	struct s_stack_node	*p;

	p = s->top;
	while (p && p->next)
	{
		if (p->val > p->next->val)
			return (0);
		p = p->next;
	}
	return (1);
}

//void	display_stack(t_stack *a)
//{
//    struct s_stack_node *tmp;
//
//    if (a == NULL)
//        return;
//    ft_putstr("===== Stack: =======\n");
//    tmp = a->top;
//    while (tmp != NULL)
//    {
//        printf("%d\n", tmp->val);
//	    ft_putstr();
//        tmp = tmp->next;
//    }
//    ft_putstr("====================\n");
//}
