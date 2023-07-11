/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:31:57 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/12 16:31:57 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *s)
{
    s->top = NULL;
    s->last = NULL;
    s->length = 0;
}

int	stack_is_empty(t_stack *s)
{
    if (s->top == NULL)
        return (1);
    return (0);
}

void	push(t_stack *s, int val)
{
    struct s_stack_node	*new_node;

    new_node = (struct s_stack_node *)malloc(sizeof(struct s_stack_node));
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (s->top == NULL)
    {
        s->top = new_node;
        s->last = new_node;
    }
    else
    {
        new_node->next = s->top;
        s->top->prev = new_node;
        s->top = new_node;
    }
    s->length++;
}

int	pop(t_stack *s)
{
    struct s_stack_node	*p;
    int					val;

    p = s->top;
    val = p->val;
    s->top = s->top->next;
    if (s->top == NULL)
        s->last = NULL;
    else
        s->top->prev = NULL;
    free(p);
    s->length--;
    return (val);
}

void    free_stack(t_stack *s)
{
    struct s_stack_node *p;

    while (s->top)
    {
        p = s->top;
        s->top = s->top->next;
        free(p);
    }
    free(s);
}