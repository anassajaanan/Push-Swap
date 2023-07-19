/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:06:45 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 17:34:08 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int is_valid_instruction(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0
		|| ft_strcmp(str, "pa\n") == 0 || ft_strcmp(str, "pb\n") == 0 || ft_strcmp(str, "ra\n") == 0
		|| ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0 || ft_strcmp(str, "rra\n") == 0
		|| ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		return (1);
	else
		return (0);
}

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