/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:29:38 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:29:40 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*---------------------------------------------------------------------------*/

t_stack	*ft_swap_a(t_stack *stack, int index)
{
	int	a;
	int	b;

	if (is_empty_dlist(stack->lia) || stack->lia->begin->next == NULL)
		return (stack);
	a = stack->lia->begin->value;
	b = stack->lia->begin->next->value;
	stack->lia = dlist_pop_front(stack->lia);
	stack->lia = dlist_pop_front(stack->lia);
	stack->lia = dlist_push_front(stack->lia, a);
	stack->lia = dlist_push_front(stack->lia, b);
	if (index == 1)
		ft_putstr_fd("sa\n", 1);
	return (stack);
}

/*---------------------------------------------------------------------------*/

t_stack	*ft_swap_b(t_stack *stack, int index)
{
	int	a;
	int	b;

	if (is_empty_dlist(stack->lib) || stack->lib->begin->next == NULL)
		return (stack);
	a = stack->lib->begin->value;
	b = stack->lib->begin->next->value;
	stack->lib = dlist_pop_front(stack->lib);
	stack->lib = dlist_pop_front(stack->lib);
	stack->lib = dlist_push_front(stack->lib, a);
	stack->lib = dlist_push_front(stack->lib, b);
	if (index == 1)
		ft_putstr_fd("sb\n", 1);
	return (stack);
}

/*---------------------------------------------------------------------------*/

t_stack	*ft_swap_ss(t_stack *stack)
{
	stack = ft_swap_a(stack, 0);
	stack = ft_swap_b(stack, 0);
	ft_putstr_fd("ss\n", 1);
	return (stack);
}

/*---------------------------------------------------------------------------*/

t_stack	*ft_push_a(t_stack *stack, int index)
{
	int	a;

	if (is_empty_dlist(stack->lib))
		return (stack);
	a = stack->lib->begin->value;
	stack->lib = dlist_pop_front(stack->lib);
	stack->lia = dlist_push_front(stack->lia, a);
	if (index == 1)
		ft_putstr_fd("pa\n", 1);
	return (stack);
}

/*---------------------------------------------------------------------------*/

t_stack	*ft_push_b(t_stack *stack, int index)
{
	int	b;

	if (is_empty_dlist(stack->lia))
		return (stack);
	b = stack->lia->begin->value;
	stack->lia = dlist_pop_front(stack->lia);
	stack->lib = dlist_push_front(stack->lib, b);
	if (index == 1)
		ft_putstr_fd("pb\n", 1);
	return (stack);
}
