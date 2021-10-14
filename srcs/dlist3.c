/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:34:06 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:34:57 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

t_dlist	*dlist_push_back(t_dlist *li, int n)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (element == NULL)
		exit(1);
	element->value = n;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_dlist(li))
	{
		li = dlist_init(li);
		li->begin = element;
	}
	else
	{
		li->end->next = element;
		element->back = li->end;
	}
	li->end = element;
	li->length++;
	return (li);
}

/*----------------------------------------------------------------------------*/

t_dlist	*dlist_push_front(t_dlist *li, int n)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (element == NULL)
		exit(1);
	element->value = n;
	element->back = NULL;
	element->next = NULL;
	if (is_empty_dlist(li))
	{
		li = dlist_init(li);
		li->end = element;
	}
	else
	{
		li->begin->back = element;
		element->next = li->begin;
	}
	li->begin = element;
	li->length++;
	return (li);
}

/*----------------------------------------------------------------------------*/

t_dlist	*dlist_pop_back(t_dlist *li)
{
	t_node	*tmp;

	if (is_empty_dlist(li))
		return (new_dlist());
	if (li->length == 1)
	{
		free(li->end);
		free(li);
		li = NULL;
		return (li);
	}
	tmp = li->end;
	li->end = tmp->back;
	li->end->next = NULL;
	li->length--;
	tmp->next = NULL;
	tmp->back = NULL;
	free(tmp);
	return (li);
}

/*----------------------------------------------------------------------------*/

t_dlist	*dlist_pop_front(t_dlist *li)
{
	t_node	*tmp;

	if (is_empty_dlist(li))
		return (new_dlist());
	if (li->length == 1)
	{
		free(li->begin);
		free(li);
		li = NULL;
		return (new_dlist());
	}
	tmp = li->begin;
	li->begin = tmp->next;
	li->begin->back = NULL;
	li->length--;
	tmp->back = NULL;
	tmp->next = NULL;
	free(tmp);
	return (li);
}

/*----------------------------------------------------------------------------*/

t_dlist	*dlist_clear(t_dlist *li)
{
	while (is_empty_dlist(li) == 0)
		li = dlist_pop_front(li);
	return (new_dlist());
}
