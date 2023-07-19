/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:06:45 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 11:06:22 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    execute_instruction(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		ft_sa(a, 0);
		ft_sb(b, 0);
	}
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(a, b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(a, b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		ft_ra(a, 0);
		ft_rb(b, 0);
	}
	else
		execute_instruction2(a, b, str);
}

void    execute_instruction2(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		ft_rra(a, 1);
		ft_rrb(b, 0);
	}
}

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

int get_max(t_stack s)
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