///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   radix_sort_utils.c                                 :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/06/19 11:34:26 by aajaanan          #+#    #+#             */
///*   Updated: 2023/06/19 11:34:38 by aajaanan         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../include/push_swap.h"
//
//int count_bits(int max_num)
//{
//    int counter = 0;
//
//    while (max_num > 0) {
//        counter++;
//        max_num /= 2;
//    }
//    return (counter);
//}
//
//int all_bits_zero(t_stack *stack, int bit_position)
//{
//    int mask;
//    struct s_stack_node *p;
//
//    mask = 1 << bit_position;
//    p = stack->top;
//    while (p)
//    {
//        if ((p->val & mask) != 0)
//            return (0);
//        p = p->next;
//    }
//    return (1);
//}
//
//int all_bits_one(t_stack *stack, int bit_position)
//{
//    int mask;
//    struct s_stack_node *p;
//
//    mask = 1 << bit_position;
//    p = stack->top;
//    while (p)
//    {
//        if ((p->val & mask) == 0)
//            return (0);
//        p = p->next;
//    }
//    return (1);
//}
//
//void    adjust_values(t_stack *stack, int min_value)
//{
//    struct s_stack_node *p;
//
//    p = stack->top;
//    while (p)
//    {
//        p->val -= min_value;
//        p = p->next;
//    }
//}
//
//void    restore_values(t_stack *stack, int min_value)
//{
//    struct s_stack_node *p;
//
//    p = stack->top;
//    while (p)
//    {
//        p->val += min_value;
//        p = p->next;
//    }
//}