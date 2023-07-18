/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:26:24 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/18 15:26:24 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_STRING_STACK_H
#define PUSH_STRING_STACK_H

#include <stdlib.h>
#include <stdio.h>

struct s_stack_node_str
{
	char                    *val;
	struct s_stack_node_str	*next;
};

typedef struct s_stack_str
{
	struct s_stack_node_str	*top;
}						t_stack_str;

void	init_stack_str(t_stack_str *s);
void	push_str(t_stack_str *s, char *val);
char    *pop_str(t_stack_str *s);
void    free_stack_str(t_stack_str *s);

#endif //PUSH_STRING_STACK_H
