/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:31:13 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 12:14:26 by aajaanan         ###   ########.fr       */
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

void    process_instructions(t_stack *a, t_stack *b)
{
	int     error;
	char    *line;

	error = 0;
	while ((line = get_next_line(0)))
	{
		if (is_valid_instruction(line))
			execute_instruction(a, b, line);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			error = 1;
			break ;
		}
		free(line);
	}
	if (!error)
	{
		if (is_stack_sorted(a) && b->length == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
}

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = get_validated_stack(argc, argv);
	if (a == NULL)
		ft_putstr_fd("Error\n", 2);
	else
	{
		b = (t_stack *)malloc(sizeof(t_stack));
		init_stack(b);
		process_instructions(a, b);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}