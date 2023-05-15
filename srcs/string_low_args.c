/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_low_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:49:16 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/22 07:55:47 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sorting_2(t_tabl *list_a)
{
	if (get_stack_nb(list_a) != 2)
		error_exit_normal();
	if (list_a->tab > list_a->next->tab)
		swap_a(list_a);
}

static void	sorting_3(t_tabl **list_a)
{
	int	case_num;

	if (get_stack_nb(*list_a) != 3)
		error_exit_normal();
	case_num = identify_case(*list_a);
	if (case_num == 1)
		swap_a(*list_a);
	else if (case_num == 2)
	{
		swap_a(*list_a);
		reverse_rotate_a(list_a);
	}
	else if (case_num == 3)
		rotate_a(list_a);
	else if (case_num == 4)
	{
		swap_a(*list_a);
		rotate_a(list_a);
	}
	else if (case_num == 5)
		reverse_rotate_a(list_a);
}

static void	sorting_4(t_tabl **list_a, t_tabl **list_b)
{
	if (get_stack_nb(*list_a) != 4)
		error_exit_normal();
	push_b_lowest(list_a, list_b);
	sorting_3(list_a);
	push_a(list_a, list_b);
}

static void	sorting_5(t_tabl **list_a, t_tabl **list_b)
{
	if (get_stack_nb(*list_a) != 5)
		error_exit_normal();
	push_b_lowest(list_a, list_b);
	arg_indexer(list_a);
	push_b_lowest(list_a, list_b);
	sorting_3(list_a);
	push_a(list_a, list_b);
	push_a(list_a, list_b);
}

void	sorting_low(t_tabl **list_a, t_tabl **list_b)
{
	if (get_stack_nb(*list_a) == 2)
		return (sorting_2(*list_a));
	if (get_stack_nb(*list_a) == 3)
		return (sorting_3(list_a));
	if (get_stack_nb(*list_a) == 4)
		return (sorting_4(list_a, list_b));
	if (get_stack_nb(*list_a) == 5)
		return (sorting_5(list_a, list_b));
}
