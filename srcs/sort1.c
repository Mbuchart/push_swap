/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:38:34 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:39:31 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

int	ft_find(t_dlist *li, int index)
{
	int		n;
	int		i;
	t_node	*tmp;

	n = 0;
	if (index < li->length)
	{
		i = 0;
		tmp = li->begin;
		while (i < index)
		{
			tmp = tmp->next;
			i++;
		}
		n = tmp->value;
	}
	return (n);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_three(t_stack *stack)
{
	if (is_empty_dlist(stack->lia))
		return (stack);
	if (ft_find(stack->lia, 0) > ft_find(stack->lia, 1))
	{
		if (ft_find(stack->lia, 2) > ft_find(stack->lia, 1))
		{
			if (ft_find(stack->lia, 2) > ft_find(stack->lia, 0))
				stack = ft_swap_a(stack, 1);
			else if (ft_find(stack->lia, 0) > ft_find(stack->lia, 2))
				stack = ft_rotate_a(stack, 1);
		}
		else if (ft_find(stack->lia, 1) > ft_find(stack->lia, 2))
		{
			stack = ft_swap_a(stack, 1);
			stack = ft_reverse_rotate_a(stack, 1);
		}
	}
	if (ft_find(stack->lia, 1) > ft_find(stack->lia, 0))
		stack = ft_sort_three_e(stack);
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_three_e(t_stack *stack)
{
	if (ft_find(stack->lia, 1) > ft_find(stack->lia, 2))
	{
		if (ft_find(stack->lia, 2) > ft_find(stack->lia, 0))
		{
			stack = ft_swap_a(stack, 1);
			stack = ft_rotate_a(stack, 1);
		}
		else if (ft_find(stack->lia, 0) > ft_find(stack->lia, 2))
			stack = ft_reverse_rotate_a(stack, 1);
	}
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_five(t_stack *stack)
{
	if (is_empty_dlist(stack->lia))
		return (stack);
	if (ft_check_sort(stack))
		return (stack);
	while (stack->lia->length > 3)
		stack = ft_push_b(stack, 1);
	stack = ft_sort_three(stack);
	while (is_empty_dlist(stack->lib) == 0)
	{
		stack = ft_sort_five_e(stack);
		stack = ft_push_a(stack, 1);
	}
	if ((ft_find_max_a(stack) * 2) <= stack->lia->length)
	{
		while (ft_check_sort(stack) == 0)
			stack = ft_rotate_a(stack, 1);
	}
	else
	{
		while (ft_check_sort(stack) == 0)
			stack = ft_reverse_rotate_a(stack, 1);
	}
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_five_e(t_stack *stack)
{
	int	b;

	b = 0;
	b = ft_find_pos_b(stack);
	if (b * 2 <= stack->lia->length)
	{
		while (b > 0)
		{
			stack = ft_rotate_a(stack, 1);
			b--;
		}
	}
	else
	{
		while (b < stack->lia->length)
		{
			stack = ft_reverse_rotate_a(stack, 1);
			b++;
		}
	}
	return (stack);
}
