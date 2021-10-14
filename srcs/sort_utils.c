/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:40:37 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:41:02 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*---------------------------------------------------------------------*/

int	ft_max(t_dlist *li)
{
	t_node	*tmp;
	int		n;
	int		i;

	if (is_empty_dlist(li))
		return (-1);
	i = 0;
	tmp = li->begin;
	n = tmp->value;
	while (i < li->length)
	{
		if (n <= tmp->value)
			n = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (n);
}

/*---------------------------------------------------------------------*/

int	ft_min(t_dlist *li)
{
	t_node	*tmp;
	int		n;
	int		i;

	if (is_empty_dlist(li))
		return (-1);
	i = 0;
	tmp = li->begin;
	n = tmp->value;
	while (i < li->length)
	{
		if (n >= tmp->value)
			n = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (n);
}

/*---------------------------------------------------------------------*/

int	ft_scan_a_top(t_stack *stack, int a, int b)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (is_empty_dlist(stack->lia))
		return (-1);
	tmp = stack->lia->begin;
	while (tmp)
	{
		if (a <= tmp->value && tmp->value <= b)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

/*---------------------------------------------------------------------*/

int	ft_scan_a_bottom(t_stack *stack, int a, int b)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (is_empty_dlist(stack->lia))
		return (-1);
	tmp = stack->lia->end;
	while (tmp)
	{
		if (a <= tmp->value && tmp->value <= b)
			return (i);
		i++;
		tmp = tmp->back;
	}
	return (-1);
}

/*---------------------------------------------------------------------*/

int	ft_find_max_b(t_stack *stack)
{
	t_node	*tmp;
	int		i;
	int		n;

	if (is_empty_dlist(stack->lib))
		return (-1);
	i = 0;
	tmp = stack->lib->begin;
	n = tmp->value;
	while (tmp != NULL)
	{
		if (n <= tmp->value)
			n = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack->lib->begin;
	while (tmp != NULL)
	{
		if (n == tmp->value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
