/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:31:17 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:32:46 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

t_dlist	*new_dlist(void)
{
	return (NULL);
}

/*----------------------------------------------------------------------------*/

t_dlist	*dlist_init(t_dlist *li)
{
	li = malloc(sizeof(t_dlist));
	if (li == NULL)
		exit(1);
	li->length = 0;
	li->begin = NULL;
	li->end = NULL;
	return (li);
}

/*----------------------------------------------------------------------------*/

int	is_empty_dlist(t_dlist *li)
{
	if (li == NULL)
		return (1);
	return (0);
}

/*----------------------------------------------------------------------------*/

void	print_dlist(t_dlist *li)
{
	t_node	*tmp;

	if (is_empty_dlist(li))
	{
		printf("dlist empty.\n");
		return ;
	}
	tmp = li->begin;
	while (tmp != NULL)
	{
		printf("[%d] ,", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
