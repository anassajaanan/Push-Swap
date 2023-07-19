/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:31:13 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 07:07:03 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/get_next_line.h"
#include "../include/lib.h"


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
			printf("Error\n");
			free(line);
			error = 1;
			break ;
		}
		free(line);
	}
	if (!error)
	{
		if (is_stack_sorted(a) && b->length == 0)
			printf("OK\n");
		else
			printf("KO\n");
	}
}

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = get_validated_stack(argc, argv);
	if (a == NULL)
		printf("Error\n");
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