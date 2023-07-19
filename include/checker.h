/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:49:12 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 11:00:25 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_CHECKER_H
#define PUSH_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include "../include/lib.h"
# include "../include/stack.h"

// args.c
int	        has_duplicates(t_stack *s);
t_stack_str *parse_arguments(int argc, char *argv[]);
void        create_validated_stack(t_stack *a, t_stack_str *args, int *is_valid);
t_stack     *get_validated_stack(int argc, char *argv[]);

//  utils.c
int	    get_min(t_stack s);
int     get_max(t_stack s);
int	    is_stack_sorted(t_stack *s);

// checker_utils.c
int     is_valid_instruction(char *str);
void    execute_instruction(t_stack *a, t_stack *b, char *str);
void    execute_instruction2(t_stack *a, t_stack *b, char *str);

#endif //PUSH_CHECKER_H
