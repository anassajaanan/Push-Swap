/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:52:16 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/19 11:23:47 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//void	swap(int *a, int *b)
//{
//    int temp;
//
//    temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void	bubble_sort(int A[], int size)
//{
//    int	i;
//    int	j;
//    int	flag;
//
//    i = 0;
//    while (i < size - 1)
//    {
//        j = 0;
//        flag = 0;
//        while (j < size - 1 - i)
//        {
//            if (A[j] > A[j + 1])
//            {
//                swap(&A[j], &A[j + 1]);
//                flag = 1;
//            }
//            j++;
//        }
//        if (flag == 0)
//            return ;
//        i++;
//    }
//}
//
//
//
//void    stack_to_array(int *array, t_stack *stack, int length)
//{
//    int i;
//    struct s_stack_node *p;
//
//    i = 0;
//    p = stack->top;
//    while (i < length)
//    {
//        array[i] = p->val;
//        p = p->next;
//        i++;
//    }
//}
//
//int get_pivot(int *array, int length)
//{
//    bubble_sort(array, length);
//    return (array[length / 2]);
//}
