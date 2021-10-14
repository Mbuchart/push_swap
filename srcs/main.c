/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:35:03 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:36:01 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------------*/

t_dlist	*ft_error(t_dlist *li)
{
	li = dlist_clear(li);
	ft_putstr_fd("Error\n", 1);
	return (NULL);
}

/*----------------------------------------------------------------------------*/

int	ft_check_arg(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg);
	if (len == 0)
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0 && arg[i] != '-' && arg[i] != ' ')
			return (2);
		i++;
	}
	return (1);
}

/*----------------------------------------------------------------------------*/

int	ft_check_duplicate(t_dlist *li)
{
	int		i;
	int		j;
	int		temp;
	t_node	*tmp;

	if (is_empty_dlist(li))
		return (0);
	i = 0;
	while (i < li->length)
	{
		j = 0;
		tmp = li->begin;
		temp = ft_search_dlist(li, i);
		while (j < i)
		{
			if (tmp->value == temp)
				return (1);
			j++;
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

/*----------------------------------------------------------------------------*/

t_dlist	*parse_dlist(t_dlist *li, char **arg, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		if (ft_check_arg(arg[i]) == 1)
			li = ft_parse_dlist_w(li, arg, &i, &j);
		else if (ft_check_arg(arg[i]) == 2)
			return (ft_error(li));
		i++;
	}
	if (ft_check_duplicate(li) == 1)
		return (ft_error(li));
	return (li);
}

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		exit(0);
	stack->lia = new_dlist();
	stack->lib = new_dlist();
	if (argc <= 1)
	{
		free(stack);
		return (0);
	}
	stack->lia = parse_dlist(stack->lia, argv, argc);
	if (is_empty_dlist(stack->lia) == 0)
		stack = ft_parse_sort(stack);
	stack->lia = dlist_clear(stack->lia);
	stack->lib = dlist_clear(stack->lib);
	free(stack);
	return (0);
}
