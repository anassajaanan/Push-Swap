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

void	handle_arguments(int argc, char *argv[], int *size, char ***args)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		*args = ft_split(argv[1], ' ');
		while ((*args)[i])
			i++;
		*size = i;
	}
	else if (argc > 2)
	{
		*size = argc - 1;
		*args = argv + 1;
	}
}

void    create_validated_stack(int size, char **args, t_stack *a, int *is_valid)
{
	int i;
	long int    num;

	i = size - 1;
	while (i >= 0)
	{
		if (is_numeric(args[i]))
		{
			num = ft_atoi(args[i]);
			if (num > INT_MAX || num < INT_MIN)
			{
				*is_valid = 0;
				break ;
			}
			else
				push(a, (int)num);
		}
		else
		{
			*is_valid = 0;
			break ;
		}
		i--;
	}
}

t_stack *get_validated_stack(int size, char **args)
{
	t_stack *a;
	int is_valid;

	is_valid = 1;
	a = (t_stack *)malloc(sizeof(t_stack));
	init_stack(a);
	if (size == 0)
		return (a);
	create_validated_stack(size, args, a, &is_valid);
	if (!is_valid || has_duplicates(a))
	{
		free_stack(a);
		return (NULL);
	}
	return (a);
}