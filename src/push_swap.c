/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:37:40 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/24 23:07:42 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_small(t_stack *a)
{
	if (a->length <= 1)
		return ;
	else if (a->length == 2)
	{
		if (a->top->val > a->top->next->val)
			ft_sa(a);
	}
	else if (a->length == 3)
	{
		int max = get_max(*a);
		if (a->top->val == max)
			ft_ra(a);
		else if (a->top->next->val == max)
			ft_rra(a);
		if (a->top->val > a->top->next->val)
			ft_sa(a);
	}
}

int get_top_cost(t_stack *s, int val)
{
	struct s_stack_node *temp;

	temp = s->top;
	int i = 0;
	while (temp && temp->val != val)
	{
		temp = temp->next;
		i++;
	}
	if (i <= s->length / 2)
		return (i);
	else
		return (-(s->length - i));
}

int find_best_target_in_stack_b(t_stack *b, int src_value_a)
{
	t_stack             s;
	struct s_stack_node *temp;

	init_stack(&s);
	temp = b->top;
	while (temp)
	{
		if (temp->val < src_value_a)
			push(&s, temp->val);
		temp = temp->next;
	}
	if (s.length == 0)
		return (get_max(*b));
	else
		return (get_max(s));
}

int find_best_target_in_stack_a(t_stack *a, int src_value_b)
{
	t_stack             s;
	struct s_stack_node *temp;

	init_stack(&s);
	temp = a->top;
	while (temp)
	{
		if (temp->val > src_value_b)
			push(&s, temp->val);
		temp = temp->next;
	}
	if (s.length == 0)
		return (get_min(*a));
	else
		return (get_min(s));
}

void    rotate_stack_a(t_stack *a, int cost)
{
	int i;

	i = 0;
	if (cost >= 0)
	{
		while (i < cost)
		{
			ft_ra(a);
			i++;
		}
	}
	else
	{
		while (i < abs(cost))
		{
			ft_rra(a);
			i++;
		}
	}
}

void    rotate_stack_b(t_stack *b, int cost)
{
	int i;

	i = 0;
	if (cost >= 0)
	{
		while (i < cost)
		{
			ft_rb(b);
			i++;
		}
	}
	else
	{
		while (i < abs(cost))
		{
			ft_rrb(b);
			i++;
		}
	}
}

struct s_min_cost *find_min_cost_a(t_stack *a, t_stack *b)
{
	int min_cost;
	int src_cost;
	int target_cost;
	struct s_stack_node *temp;
	struct s_min_cost *min_cost_data;

	min_cost = INT_MAX;
	temp = a->top;
	min_cost_data = (struct s_min_cost *)malloc(sizeof(struct s_min_cost));
	while (temp)
	{
		src_cost = get_top_cost(a, temp->val);
		target_cost = get_top_cost(b, find_best_target_in_stack_b(b, temp->val));
		if (abs(src_cost) + abs(target_cost) < min_cost)
		{
			min_cost_data->src_cost = src_cost;
			min_cost_data->target_cost = target_cost;
			min_cost = abs(src_cost) + abs(target_cost);
		}
		temp = temp->next;
	}
	return (min_cost_data);
}

struct s_min_cost   *find_min_cost_b(t_stack *a, t_stack *b)
{
	int min_cost;
	int src_cost;
	int target_cost;
	struct s_stack_node *temp;
	struct s_min_cost *min_cost_data;

	min_cost = INT_MAX;
	temp = b->top;
	min_cost_data = (struct s_min_cost *)malloc(sizeof(struct s_min_cost));
	while (temp)
	{
		src_cost = get_top_cost(b, temp->val);
		target_cost = get_top_cost(a, find_best_target_in_stack_a(a, temp->val));
		if (abs(src_cost) + abs(target_cost) < min_cost)
		{
			min_cost_data->src_cost = src_cost;
			min_cost_data->target_cost = target_cost;
			min_cost = abs(src_cost) + abs(target_cost);
		}
		temp = temp->next;
	}
	return (min_cost_data);
}

void    move_min_to_top(t_stack *a)
{
	int i;
	int min;
	int instructions;

	i = 0;
	min = get_min(*a);
	instructions = get_top_cost(a, min);
	if (instructions >= 0)
	{
		while (i < instructions)
		{
			ft_ra(a);
			i++;
		}
	}
	else
	{
		while ( i < abs(instructions))
		{
			ft_rra(a);
			i++;
		}
	}
}


void    cost_sort(t_stack *a, t_stack *b)
{
	struct s_min_cost *min_cost_data;

	while (b->top)
	{
		min_cost_data = find_min_cost_b(a, b);
		rotate_stack_a(a, min_cost_data->target_cost);
		rotate_stack_b(b, min_cost_data->src_cost);
		free(min_cost_data);
		ft_pa(a, b);
	}
	move_min_to_top(a);
}

// quick sort

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int A[], int size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		flag = 0;
		while (j < size - 1 - i)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			return ;
		i++;
	}
}

void    stack_to_array(int *array, t_stack *stack, int length)
{
	int i;
	struct s_stack_node *p;

	i = 0;
	p = stack->top;
	while (i < length)
	{
		array[i] = p->val;
		p = p->next;
		i++;
	}
}

int get_pivot(t_stack *stack, int length)
{
	int *array = (int *)malloc(sizeof(int) * length);
	stack_to_array(array, stack, length);
	bubble_sort(array, length);
	int pivot = array[length / 2];
	free(array);
	return (pivot);
}

void    quick_sort(t_stack *a, t_stack *b)
{
	if (a->length <= 3)
		sort_small(a);
	else
	{
		int pivot = get_pivot(a, a->length);
		int i = 0;
		int len = a->length / 2;
		while (i < len)
		{
			if (a->top->val < pivot)
			{
				ft_pb(a, b);
				i++;
			}
			else if (a->last->val < pivot)
			{
				ft_rra(a);
				ft_pb(a, b);
				i++;
			}
			else
				ft_ra(a);
		}
		quick_sort(a, b);
	}
}

void    quick_cost_sort(t_stack *a, t_stack *b)
{
	if (is_a_sorted(a))
		return;
	if(a->length <= 3)
		sort_small(a);
	else if (a->length > 3)
	{
		quick_sort(a, b);
		sort_small(a);
		cost_sort(a, b);
	}
}


int main(int argc, char *argv[])
{
    int size;
    char **args = NULL;
    t_stack *a;
    t_stack	*b;

    handle_arguments(argc, argv, &size, &args);
    a = get_validated_stack(size, args);
    if (a == NULL)
        printf("Error\n");
    else
    {
        b = (t_stack *)malloc(sizeof(t_stack));
        init_stack(b);


	    quick_cost_sort(a, b);



//	    display_stack(a);
//	    display_stack(b);

        free(b);
        free_stack(a);

    }
    if (argc == 2 && args)
    {
        for (int i = 0; args[i]; i++)
            free(args[i]);
        free(args);
    }
}




