/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:22:27 by mabuchar          #+#    #+#             */
/*   Updated: 2021/09/13 22:28:34 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*-------------------definition maillon------------------*/

typedef struct s_node	t_node;
struct s_node
{
	int		value;
	t_node	*back;
	t_node	*next;
};

/*-------------------definition liste--------------------*/

typedef struct s_dlist	t_dlist;
struct	s_dlist
{
	int		length;
	t_node	*begin;
	t_node	*end;
};

/*----------------definition struct stacks--------------*/

typedef struct s_stack	t_stack;
struct s_stack
{
	t_dlist	*lia;
	t_dlist	*lib;
};

/*-------------------prototypes-------------------------*/

t_dlist	*new_dlist(void);
t_dlist	*dlist_init(t_dlist *li);
int		is_empty_dlist(t_dlist *li);
void	print_dlist(t_dlist *li);
int		dlist_length(t_dlist *li);
int		dlist_begin(t_dlist *li);
int		dlist_end(t_dlist *li);
t_dlist	*dlist_push_back(t_dlist *li, int n);
t_dlist	*dlist_push_front(t_dlist *li, int n);
t_dlist	*dlist_pop_back(t_dlist *li);
t_dlist	*dlist_pop_front(t_dlist *li);
t_dlist	*dlist_clear(t_dlist *li);
t_dlist	*parse_dlist(t_dlist *li, char **arg, int len);
int		ft_check_arg(char *arg);
t_dlist	*ft_error(t_dlist *li);
int		ft_search_dlist(t_dlist *li, int index);
int		ft_check_duplicate(t_dlist *li);
long	ft_atoi_sp(char *str, int *i);
t_stack	*ft_swap_a(t_stack *stack, int index);
t_stack	*ft_swap_b(t_stack *stack, int index);
t_stack	*ft_swap_ss(t_stack *stack);
t_stack	*ft_push_a(t_stack *stack, int index);
t_stack	*ft_push_b(t_stack *stack, int index);
t_stack	*ft_rotate_a(t_stack *stack, int index);
t_stack	*ft_rotate_b(t_stack *stack, int index);
t_stack	*ft_rotate_rr(t_stack *stack);
t_stack	*ft_reverse_rotate_a(t_stack *stack, int index);
t_stack	*ft_reverse_rotate_b(t_stack *stack, int index);
t_stack	*ft_reverse_rotate_rrr(t_stack *stack);
int		ft_find(t_dlist *li, int index);
int		ft_check_sort(t_stack *stack);
t_stack	*ft_sort_three(t_stack *stack);
t_stack	*ft_sort_three_e(t_stack *stack);
t_stack	*ft_sort_five(t_stack *stack);
t_stack	*ft_sort_five_e(t_stack *stack);
int		ft_find_pos_b(t_stack *stack);
int		ft_find_max_a(t_stack *stack);
int		ft_find_min_a(t_stack *stack);
int		ft_max(t_dlist *li);
int		ft_min(t_dlist *li);
int		ft_scan_a_top(t_stack *stack, int a, int b);
int		ft_scan_a_bottom(t_stack *stack, int a, int b);
int		ft_find_max_b(t_stack *stack);
t_stack	*ft_sort_hundred(t_stack *stack, int num_chunk);
t_stack	*ft_sort_pb(t_stack *stack, int a, int b);
t_stack	*ft_parse_sort(t_stack *stack);
t_stack	*ft_sort_pa(t_stack *stack);
t_stack	*ft_sort_pb_w(t_stack *stack, int t, int bo);
t_dlist	*ft_parse_dlist_w(t_dlist *li, char **arg, int *i, int *j);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
