/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:37:22 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:38:20 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*--------------------------------------------------------------------------*/

int	ft_check_sort(t_stack *stack)
{
	t_node	*tmp;
	t_node	*before;

	if (is_empty_dlist(stack->lib) == 0)
		return (0);
	tmp = stack->lia->begin;
	before = tmp;
	while (tmp != NULL)
	{
		if (tmp->value < before->value)
			return (0);
		before = tmp;
		tmp = tmp->next;
	}
	return (1);
}

/*--------------------------------------------------------------------------*/

int	ft_find_pos_b(t_stack *stack)
{
	t_node	*tmp;
	t_node	*before;
	int		i;
	int		n;

	if (is_empty_dlist(stack->lib))
		return (-1);
	i = 0;
	n = stack->lib->begin->value;
	tmp = stack->lia->begin;
	before = stack->lia->end;
	while (tmp != NULL)
	{
		if (n > before->value && n < tmp->value)
			return (i);
		i++;
		before = tmp;
		tmp = tmp->next;
	}
	if (n > before->value)
		i = ft_find_max_a(stack);
	else
		i = ft_find_min_a(stack);
	return (i);
}

/*--------------------------------------------------------------------------*/

int	ft_find_max_a(t_stack *stack)
{
	t_node	*tmp;
	int		i;
	int		n;

	if (is_empty_dlist(stack->lia))
		return (-1);
	i = 0;
	tmp = stack->lia->begin;
	n = tmp->value;
	while (tmp != NULL)
	{
		if (n <= tmp->value)
			n = tmp->value;
		else
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*--------------------------------------------------------------------------*/

int	ft_find_min_a(t_stack *stack)
{
	t_node	*tmp;
	int		i;
	int		n;

	if (is_empty_dlist(stack->lia))
		return (-1);
	i = 0;
	tmp = stack->lia->end;
	n = tmp->value;
	while (tmp != NULL)
	{
		if (n >= tmp->value)
			n = tmp->value;
		else
			break ;
		i++;
		tmp = tmp->back;
	}
	i = stack->lia->length - i;
	return (i);
}

/*--------------------------------------------------------------------------*/

int	ft_check_sort_dlist(t_dlist *li)
{
	t_node	*tmp;
	t_node	*before;

	if (is_empty_dlist(li) == 0)
		return (0);
	tmp = li->begin;
	before = tmp;
	while (tmp != NULL)
	{
		if (tmp->value < before->value)
			return (0);
		before = tmp;
		tmp = tmp->next;
	}
	return (1);
}
