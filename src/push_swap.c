/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:37:40 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 16:22:38 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quick_cost_sort(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a))
		return ;
	if (a->length <= 3)
		sort_small(a);
	else if (a->length > 3)
	{
		quick_sort(a, b);
		sort_small(a);
		cost_sort(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	**args;

	args = NULL;
	handle_arguments(argc, argv, &size, &args);
	a = get_validated_stack(size, args);
	if (a == NULL)
		printf("Error\n");
	else
	{
		b = (t_stack *)malloc(sizeof(t_stack));
		init_stack(b);
		quick_cost_sort(a, b);
		free(b);
		free_stack(a);
	}
	if (argc == 2 && args)
		free_args(args);
}
