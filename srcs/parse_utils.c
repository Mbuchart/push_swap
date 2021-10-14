/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:36:08 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:37:08 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*----------------------------------------------------------------------*/

long	ft_atoi_sp(char *str, int *i)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	if (str[*i] == '-')
	{
		sign *= -1;
		n *= -1;
		*i += 1;
	}
	while (ft_isdigit(str[*i]))
	{
		n += str[*i] - '0';
		*i += 1;
		if (ft_isdigit(str[*i]))
			n *= 10;
	}
	return (n * sign);
}

/*----------------------------------------------------------------------*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

/*----------------------------------------------------------------------*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*----------------------------------------------------------------------*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*----------------------------------------------------------------------*/

t_dlist	*ft_parse_dlist_w(t_dlist *li, char **arg, int *i, int *j)
{
	long	n;

	while (arg[*i][*j])
	{
		n = 0;
		if (ft_isdigit(arg[*i][*j]) || arg[*i][*j] == '-')
		{
			n = ft_atoi_sp(arg[*i], j);
			if (n >= -2147483648 && n <= 2147483647)
				li = dlist_push_back(li, (int)n);
			else
				return (ft_error(li));
		}
		else
			*j += 1;
	}
	return (li);
}
