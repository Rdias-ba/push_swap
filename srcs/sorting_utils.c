/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:35:30 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/15 17:54:20 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_is_sorted(t_tabl *list)
{
	int	i;

	i = list->tab;
	if (!list->next && list)
		return (1);
	while (list->next)
	{
		list = list->next;
		if (i > list->tab)
			return (0);
		i = list->tab;
	}
	return (1);
}

int	identify_case(t_tabl *list_a)
{
	int	arg_1;
	int	arg_2;
	int	arg_3;

	arg_1 = list_a->tab;
	arg_2 = list_a->next->tab;
	arg_3 = list_a->next->next->tab;
	if (arg_2 < arg_1 && arg_1 < arg_3)
		return (1);
	if (arg_3 < arg_2 && arg_2 < arg_1)
		return (2);
	if (arg_2 < arg_3 && arg_3 < arg_1)
		return (3);
	if (arg_1 < arg_3 && arg_3 < arg_2)
		return (4);
	if (arg_3 < arg_1 && arg_1 < arg_2)
		return (5);
	return (0);
}

int	lowest_in_stack(t_tabl *list)
{
	int	i;

	i = list->tab;
	while (list->next)
	{
		list = list->next;
		if (i > list->tab)
			i = list->tab;
	}
	return (i);
}

void	push_b_lowest(t_tabl **list_a, t_tabl **list_b)
{
	t_tabl	*temp;
	int		lowest_nb;

	lowest_nb = lowest_in_stack(*list_a);
	temp = lastcell(*list_a);
	if (temp->tab == lowest_nb)
	{
		reverse_rotate_a(list_a);
		push_b(list_a, list_b);
	}
	else
	{
		while (*list_a)
		{
			if ((*list_a)->index == 0)
			{
				push_b(list_a, list_b);
				break ;
			}
			rotate_a(list_a);
		}
	}
}

void	sort_tab(t_tabl **list_a, t_tabl **list_b)
{
	if (check_is_sorted(*list_a))
		return ;
	if (get_stack_nb(*list_a) <= 5)
		return (sorting_low(list_a, list_b));
	sorting_big(list_a, list_b);
}
