/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:33:07 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:33:55 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

int	dlist_length(t_dlist *li)
{
	if (is_empty_dlist(li))
		return (0);
	return (li->length);
}

/*----------------------------------------------------------------------------*/

int	dlist_begin(t_dlist *li)
{
	if (is_empty_dlist(li))
		exit(1);
	return (li->begin->value);
}

/*----------------------------------------------------------------------------*/

int	dlist_end(t_dlist *li)
{
	if (is_empty_dlist(li))
		exit(1);
	return (li->end->value);
}

/*----------------------------------------------------------------------------*/

int	ft_search_dlist(t_dlist *li, int index)
{
	int		i;
	int		n;
	t_node	*tmp;

	i = 0;
	n = 0;
	tmp = li->begin;
	while (i <= index)
	{
		if (i == index)
		{
			n = tmp->value;
			return (n);
		}
		i++;
		tmp = tmp->next;
	}
	return (n);
}
