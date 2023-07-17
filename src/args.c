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

int	is_numeric(const char *str)
{
	if (*str && (*str == '-' || *str == '+'))
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

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
	else
	{
		*size = argc - 1;
		*args = argv + 1;
	}
}

t_stack	*get_validated_stack(int size, char **args)
{
	int			i;
	t_stack		*a;
	long int	num;

	a = (t_stack *)malloc(sizeof(t_stack));
	init_stack(a);
	if (size == 0)
		return (a);
	i = size - 1;
	while (i >= 0)
	{
		if (is_numeric(args[i]))
		{
			num = ft_atoi(args[i]);
			if (num > INT_MAX || num < INT_MIN)
				return (NULL);
			else
				push(a, (int)num);
		}
		else
			return (NULL);
		i--;
	}
	if (has_duplicates(a))
		return (NULL);
	return (a);
}
