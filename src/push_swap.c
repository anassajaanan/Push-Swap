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

int cost_to_bring_to_top(t_stack *s, int val)
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

int find_best_target_in_stack_b(t_stack *b, int source_val)
{
	t_stack             s;
	struct s_stack_node *temp;

	init_stack(&s);
	temp = b->top;
	while (temp)
	{
		if (temp->val < source_val)
			push(&s, temp->val);
		temp = temp->next;
	}
	if (s.length == 0)
		return (get_max(*b));
	else
		return (get_max(s));
}

int find_best_target_in_stack_a(t_stack *a, int source_val)
{
	t_stack             s;
	struct s_stack_node *temp;

	init_stack(&s);
	temp = a->top;
	while (temp)
	{
		if (temp->val > source_val)
			push(&s, temp->val);
		temp = temp->next;
	}
	if (s.length == 0)
		return (get_min(*a));
	else
		return (get_min(s));
}

int get_target_of_a(t_stack *b, int val)
{
	t_stack s;
	init_stack(&s);
	struct s_stack_node *temp = b->top;
	while (temp)
	{
		if (temp->val < val)
			push(&s, temp->val);
		temp = temp->next;
	}
	if (s.length == 0)
		return (get_max(*b));
	else
		return (get_max(s));
}

int get_target_of_b(t_stack *a, int val)
{
	t_stack s;
	init_stack(&s);
	struct s_stack_node *temp = a->top;
	while (temp)
	{
		if (temp->val > val)
			push(&s, temp->val);
		temp = temp->next;
	}
	if (s.length == 0)
		return (get_min(*a));
	else
		return (get_min(s));
}

//int count_cost(t_stack *b, int val)
//{
//	int cost = 0;
//	int min = get_min(*b);
//	int max = get_max(*b);
//
//
//}


void    sort(t_stack *a, t_stack *b)
{
	while (a->length > 3)
	{
		if (b->length < 2)
			ft_pb(a, b);
		else
		{
			t_stack cost;
			init_stack(&cost);
			struct s_stack_node *temp = a->last;
			while (temp)
			{
				push(&cost, abs(cost_to_bring_to_top(a, temp->val)) + abs(cost_to_bring_to_top(b, find_best_target_in_stack_b(b, temp->val))));
				temp = temp->prev;
			}
			int min = get_min(cost);
			temp = a->top;
			struct s_stack_node *temp2 = cost.top;
			while (temp2 && temp && temp2->val != min)
			{
				temp = temp->next;
				temp2 = temp2->next;
			}
			int cost_src = cost_to_bring_to_top(a, temp->val);
			if (cost_src >= 0)
			{
				int i = 0;
				while (i < cost_src)
				{
					ft_ra(a);
					i++;
				}
			}
			else
			{
				int i = 0;
				while ( i < abs(cost_src))
				{
					ft_rra(a);
					i++;
				}
			}
			int cost_dst = cost_to_bring_to_top(b, find_best_target_in_stack_b(b, temp->val));
			if (cost_dst >= 0)
			{
				int j = 0;
				while (j < cost_dst)
				{
					ft_rb(b);
					j++;
				}
			}
			else
			{
				int j = 0;
				while ( j < abs(cost_dst))
				{
					ft_rrb(b);
					j++;
				}
			}
			ft_pb(a, b);
		}
	}

}

void    sort2(t_stack *a, t_stack *b)
{
	while (b->top)
	{
		t_stack cost;
		init_stack(&cost);
		struct s_stack_node *temp = b->last;
		while (temp)
		{
			push(&cost, abs(cost_to_bring_to_top(b, temp->val)) + abs(cost_to_bring_to_top(a, get_target_of_b(a, temp->val))));
			temp = temp->prev;
		}
		int min = get_min(cost);
		temp = b->top;
		struct s_stack_node *temp2 = cost.top;
		while (temp2 && temp && temp2->val != min)
		{
			temp = temp->next;
			temp2 = temp2->next;
		}
		int cost_src = cost_to_bring_to_top(b, temp->val);
		if (cost_src >= 0)
		{
			int i = 0;
			while (i < cost_src)
			{
				ft_rb(b);
				i++;
			}
		}
		else
		{
			int i = 0;
			while ( i < abs(cost_src))
			{
				ft_rrb(b);
				i++;
			}
		}
		int cost_dst = cost_to_bring_to_top(a, get_target_of_b(a, temp->val));
		if (cost_dst >= 0)
		{
			int j = 0;
			while (j < cost_dst)
			{
				ft_ra(a);
				j++;
			}
		}
		else
		{
			int j = 0;
			while ( j < abs(cost_dst))
			{
				ft_rra(a);
				j++;
			}
		}
		ft_pa(a, b);



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


	    sort(a, b);
	    sort_small(a);
	    sort2(a, b);

	    int mmin = get_min(*a);
	    int instructions = cost_to_bring_to_top(a, mmin);
	    int i = 0;
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




