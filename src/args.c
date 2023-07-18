/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:37:12 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 15:45:16 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/lib.h"
#include "../include/string_stack.h"

int	has_duplicates(t_stack *s)
{
	int					i;
	int					j;
	int					*array;

	i = 0;
	array = (int *)malloc(sizeof(int) * s->length);
	stack_to_array(array, s);
	i = 0;
	while (i < s->length - 1)
	{
		j = i + 1;
		while (j < s->length)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(array);
	return (0);
}

t_stack_str *parse_arguments(int argc, char *argv[])
{
	int         i;
	int         j;
	t_stack_str *s;
	char        **args;

	i = 1;
	s = (t_stack_str *)malloc(sizeof(t_stack_str));
	init_stack_str(s);
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (args[0] == NULL)
			push_str(s, ft_strdup("space"));
		j = 0;
		while (args[j])
		{
			push_str(s, args[j]);
			j++;
		}
		free(args);
		i++;
	}
	return (s);
}

void    create_validated_stack(t_stack *a, t_stack_str *args, int *is_valid)
{
	struct s_stack_node_str *tmp;
	long                    num;

	tmp = args->top;
	while (tmp)
	{
		if (is_numeric(tmp->val))
		{
			num = ft_atoi(tmp->val);
			if (num > INT_MAX || num < INT_MIN)
			{
				*is_valid = 0;
				return ;
			}
			push(a, (int)num);
		}
		else
		{
			*is_valid = 0;
			return ;
		}
		tmp = tmp->next;
	}
}


t_stack     *get_validated_stack(int argc, char *argv[])
{
	t_stack *a;
	int     is_valid;
	t_stack_str *args;

	is_valid = 1;
	a = (t_stack *)malloc(sizeof(t_stack));
	init_stack(a);
	args = parse_arguments(argc, argv);
	create_validated_stack(a, args, &is_valid);
	if (!is_valid || has_duplicates(a))
	{
		free_stack_str(args);
		free_stack(a);
		return (NULL);
	}
	free_stack_str(args);
	return (a);
}
