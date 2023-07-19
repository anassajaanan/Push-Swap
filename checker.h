/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:49:12 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/19 14:01:54 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "lib.h"
# include "stack.h"

/* ================ args.c ================ */
int			has_duplicates(t_stack *s);
t_stack_str	*parse_arguments(int argc, char *argv[]);
void		create_validated_stack(t_stack *a, t_stack_str *args,
				int *is_valid);
t_stack		*get_validated_stack(int argc, char *argv[]);

/* ================ Utils.c ================ */
int			get_min(t_stack s);
int			get_max(t_stack s);
int			is_stack_sorted(t_stack *s);

/* ================ checker_utils.c ================ */
int			is_valid_instruction(char *str);
void		print_result(t_stack *a, t_stack *b);
void		process_instructions(t_stack *a, t_stack *b);
void		execute_instruction(t_stack *a, t_stack *b, char *str);
void		execute_instruction2(t_stack *a, t_stack *b, char *str);

#endif //CHECKER_H
