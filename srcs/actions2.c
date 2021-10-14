/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:30:01 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:30:42 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

t_stack	*ft_rotate_a(t_stack *stack, int index)
{
	int	a;

	if (is_empty_dlist(stack->lia) || stack->lia->begin->next == NULL)
		return (stack);
	a = stack->lia->begin->value;
	stack->lia = dlist_pop_front(stack->lia);
	stack->lia = dlist_push_back(stack->lia, a);
	if (index == 1)
		ft_putstr_fd("ra\n", 1);
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_rotate_b(t_stack *stack, int index)
{
	int	b;

	if (is_empty_dlist(stack->lib) || stack->lib->begin->next == NULL)
		return (stack);
	b = stack->lib->begin->value;
	stack->lib = dlist_pop_front(stack->lib);
	stack->lib = dlist_push_back(stack->lib, b);
	if (index == 1)
		ft_putstr_fd("rb\n", 1);
	return (stack);
}

/*----------------------------------------------------------------------------*/

t_stack	*ft_rotate_rr(t_stack *stack)
{
	stack = ft_rotate_a(stack, 0);
	stack = ft_rotate_b(stack, 0);
	ft_putstr_fd("rr\n", 1);
	return (stack);
}
