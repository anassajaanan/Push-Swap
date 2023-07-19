/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:25:00 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/18 15:39:27 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	init_stack_str(t_stack_str *s)
{
	s->top = NULL;
}

void	push_str(t_stack_str *s, char *val)
{
	struct s_stack_node_str	*new_node;

	new_node = (struct s_stack_node_str *)malloc(sizeof(struct s_stack_node_str));
	new_node->val = val;
	new_node->next = NULL;
	if (s->top == NULL)
	{
		s->top = new_node;
	}
	else
	{
		new_node->next = s->top;
		s->top = new_node;
	}
}

char    *pop_str(t_stack_str *s)
{
	struct s_stack_node_str	*p;
	char                    *val;

	p = s->top;
	val = p->val;
	s->top = s->top->next;
	free(p);
	return (val);
}

void    free_stack_str(t_stack_str *s)
{
	struct s_stack_node_str	*p;

	while (s->top != NULL)
	{
		p = s->top;
		s->top = s->top->next;
		free(p->val);
		free(p);
	}
	free(s);
}