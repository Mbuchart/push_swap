/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:30:55 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:30:58 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------*/

t_stack	*ft_reverse_rotate_a(t_stack *stack, int index)
{
	int	a;

	if (is_empty_dlist(stack->lia) || stack->lia->end->back == NULL)
		return (stack);
	a = stack->lia->end->value;
	stack->lia = dlist_pop_back(stack->lia);
	stack->lia = dlist_push_front(stack->lia, a);
	if (index == 1)
		ft_putstr_fd("rra\n", 1);
	return (stack);
}

/*----------------------------------------------------------------------*/

t_stack	*ft_reverse_rotate_b(t_stack *stack, int index)
{
	int	b;

	if (is_empty_dlist(stack->lib) || stack->lib->end->back == NULL)
		return (stack);
	b = stack->lib->end->value;
	stack->lib = dlist_pop_back(stack->lib);
	stack->lib = dlist_push_front(stack->lib, b);
	if (index == 1)
		ft_putstr_fd("rrb\n", 1);
	return (stack);
}

/*----------------------------------------------------------------------*/

t_stack	*ft_reverse_rotate_rrr(t_stack *stack)
{
	stack = ft_reverse_rotate_a(stack, 0);
	stack = ft_reverse_rotate_b(stack, 0);
	ft_putstr_fd("rrr\n", 1);
	return (stack);
}
