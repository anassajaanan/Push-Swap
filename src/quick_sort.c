///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   quick_sort.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/06/19 09:51:48 by aajaanan          #+#    #+#             */
///*   Updated: 2023/06/19 11:23:59 by aajaanan         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../include/push_swap.h"
//
//void    sort_two_elements(t_stack *a)
//{
//    if (a->top->val > a->top->next->val)
//        ft_sa(a);
//}
//
//void    sort_three_elements(t_stack *a)
//{
//    int max;
//
//    max = get_max(*a);
//    if (a->top->val == max)
//        ft_ra(a);
//    else if (a->top->next->val == max)
//        ft_rra(a);
//    if (a->top->val > a->top->next->val)
//        ft_sa(a);
//}
//
//void    partition_elements(t_stack *a, t_stack *b, int pivot, int length)
//{
//    int i;
//
//    i = 0;
//    while (i < length / 2)
//    {
//        if (a->top->val < pivot)
//        {
//            ft_pb(a, b);
//            i++;
//        }
//        else
//            ft_ra(a);
//    }
//}
//
//void    insert_elements(t_stack *a, t_stack *b, int *array, int length)
//{
//    int i;
//
//    i = (length / 2) - 1;
//    while (i >= 0)
//    {
//        if (b->top->val == array[i])
//        {
//            ft_pa(a, b);
//            i--;
//        }
//        else if (b->last->val == array[i])
//        {
//            ft_rrb(b);
//            ft_pa(a, b);
//            i--;
//        }
//        else
//            ft_rb(b);
//    }
//}
//
//void    quick_sort_stacks(t_stack *a, t_stack *b)
//{
//    int len;
//    int pivot;
//    int *array;
//
//    len = a->length;
//    if (len == 2)
//        sort_two_elements(a);
//    else if (len == 3)
//        sort_three_elements(a);
//    else if (len > 3)
//    {
//        array = (int *)malloc(sizeof(int) * len);
//        stack_to_array(array, a);
//        pivot = get_pivot(array, len);
//        partition_elements(a, b, pivot, len);
//        quick_sort_stacks(a, b);
//        insert_elements(a, b, array, len);
//        free(array);
//        array = NULL;
//    }
//}
//
