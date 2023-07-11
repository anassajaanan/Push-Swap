///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   radix_sort.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/06/19 11:34:04 by aajaanan          #+#    #+#             */
///*   Updated: 2023/06/19 11:34:11 by aajaanan         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../include/push_swap.h"
//
//void    process_stack_b(t_stack *a, t_stack *b, int bit_position, int len, int *stop)
//{
//    int i;
//    int mask;
//
//    if (all_bits_zero(b, bit_position))
//        return ;
//    i = 0;
//    mask = (1 << bit_position);
//    while (i < len)
//    {
//        if (is_stack_sorted(a) && is_stack_sorted(b) && b->last->val < a->top->val)
//        {
//            *stop = 1;
//            return ;
//        }
//        if ((b->top->val & mask) == 0)
//            ft_rb(b);
//        else
//        {
//            ft_pa(a, b);
//            if (a->top && a->top->next)
//                ft_ra(a);
//        }
//        i++;
//    }
//}
//
//void    process_stack_a(t_stack *a, t_stack *b, int bit_position, int len, int *stop)
//{
//    int i;
//    int mask;
//
//    if (all_bits_one(a, bit_position))
//        return ;
//    i = 0;
//    mask = (1 << bit_position);
//    while (i < len)
//    {
//        if (is_stack_sorted(a) && is_stack_sorted(b) && b->last->val < a->top->val)
//        {
//            *stop = 1;
//            return ;
//        }
//        if ((a->top->val & mask) != 0)
//            ft_ra(a);
//        else
//        {
//            ft_pb(a, b);
//            if (b->top && b->top->next)
//                ft_rb(b);
//        }
//        i++;
//    }
//}
//
//void    process_radix_bits(t_stack *a, t_stack *b, int max_bits)
//{
//    int stop;
//    int len_b;
//    int len_a;
//    int bit_position;
//
//    stop = 0;
//    bit_position = 0;
//    while (bit_position < max_bits)
//    {
//        len_b = b->length;
//        len_a = a->length;
//        process_stack_b(a, b, bit_position, len_b, &stop);
//        if (stop)
//            return;
//        process_stack_a(a, b, bit_position, len_a, &stop);
//        if (stop)
//            return;
//        bit_position++;
//    }
//}
//
//void radix_sort_stacks(t_stack *a, t_stack *b)
//{
//    int min_value;
//    int max_value;
//    int max_bits;
//
//    max_value = get_max(*a);
//    min_value = get_min(*a);
//    max_bits = count_bits(max_value - min_value);
//    adjust_values(a, min_value);
//    process_radix_bits(a, b, max_bits);
//    while (b->top)
//    {
//        ft_rrb(b);
//        ft_pa(a, b);
//    }
//    restore_values(a, min_value);
//}
