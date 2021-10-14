/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:39:40 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:40:16 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_hundred(t_stack *stack, int num_chunk)
{
	int	a;
	int	b;
	int	chunk_index;
	int	min;

	min = ft_min(stack->lia);
	chunk_index = (ft_max(stack->lia) - min) / num_chunk;
	a = min;
	b = min + chunk_index;
	while (is_empty_dlist(stack->lia) == 0)
	{
		stack = ft_sort_pb(stack, a, b);
		a = b + 1;
		b += chunk_index;
	}
	while (is_empty_dlist(stack->lib) == 0)
		stack = ft_sort_pa(stack);
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_pb(t_stack *stack, int a, int b)
{
	int	t;
	int	bo;

	if (is_empty_dlist(stack->lia))
		return (stack);
	t = ft_scan_a_top(stack, a, b);
	bo = ft_scan_a_bottom(stack, a, b);
	while (bo != -1 && t != -1)
	{
		stack = ft_sort_pb_w(stack, t, bo);
		t = ft_scan_a_top(stack, a, b);
		bo = ft_scan_a_bottom(stack, a, b);
		if (is_empty_dlist(stack->lia))
			break ;
	}
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_pb_w(t_stack *stack, int t, int bo)
{
	if (t <= bo && bo != -1)
	{
		while (t-- > 0)
			stack = ft_rotate_a(stack, 1);
		stack = ft_push_b(stack, 1);
	}
	else if (t > bo && t != -1)
	{
		while (bo-- >= 0)
			stack = ft_reverse_rotate_a(stack, 1);
		stack = ft_push_b(stack, 1);
	}
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_sort_pa(t_stack *stack)
{
	int	p;

	p = ft_find_max_b(stack);
	if (p <= stack->lib->length / 2)
	{
		while (p-- > 0)
			stack = ft_rotate_b(stack, 1);
	}
	else
	{
		while (p++ < stack->lib->length)
			stack = ft_reverse_rotate_b(stack, 1);
	}
	stack = ft_push_a(stack, 1);
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_parse_sort(t_stack *stack)
{
	if (stack->lia->length <= 2)
	{
		if (ft_check_sort(stack))
			return (stack);
		else
			stack = ft_swap_a(stack, 1);
	}
	else if (stack->lia->length == 3)
		stack = ft_sort_three(stack);
	else if (stack->lia->length <= 10)
		stack = ft_sort_five(stack);
	else if (stack->lia->length <= 100)
		stack = ft_sort_hundred(stack, 5);
	else
		stack = ft_sort_hundred(stack, 11);
	return (stack);
}
