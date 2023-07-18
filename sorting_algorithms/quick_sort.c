/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:15:49 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/17 15:02:05 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	merge(int A[], int l, int mid, int h)
{
	int	i;
	int	j;
	int	k;
	int	*arr;

	k = 0;
	i = l;
	j = mid + 1;
	arr = (int *)malloc(sizeof(int) * (h - l + 1));
	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			arr[k++] = A[i++];
		else
			arr[k++] = A[j++];
	}
	while (i <= mid)
		arr[k++] = A[i++];
	while (j <= h)
		arr[k++] = A[j++];
	i = l;
	k = 0;
	while (i <= h)
		A[i++] = arr[k++];
	free(arr);
}

void	merge_sort(int A[], int low, int high)
{
	int	mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}

void	stack_to_array(int *array, t_stack *a)
{
	int					i;
	struct s_stack_node	*p;

	i = 0;
	p = a->top;
	while (i < a->length)
	{
		array[i] = p->val;
		p = p->next;
		i++;
	}
}

int	get_pivot(t_stack *a)
{
	int	pivot;
	int	*array;

	array = (int *)malloc(sizeof(int) * a->length);
	stack_to_array(array, a);
	merge_sort(array, 0, a->length - 1);
	pivot = array[a->length / 2];
	free(array);
	return (pivot);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	len;
	int	pivot;

	if (a->length > 3)
	{
		{
			pivot = get_pivot(a);
			i = 0;
			len = a->length / 2;
			while (i < len)
			{
				if (a->last->val < pivot)
					ft_rra(a, 1);
				if (a->top->val < pivot)
				{
					ft_pb(a, b, 1);
					i++;
				}
				else
					ft_ra(a, 1);
			}
			quick_sort(a, b);
		}
	}
}
