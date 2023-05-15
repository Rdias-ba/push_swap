/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:17:11 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/15 14:25:32 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_tabl *list)
{
	t_tabl	*temp;
	int		firstelem;
	int		secondelem;
	int		firstelem_ind;
	int		secondelem_ind;

	temp = list;
	if (!list)
		return ;
	firstelem = temp->tab;
	firstelem_ind = temp->index;
	temp = temp->next;
	secondelem = temp->tab;
	secondelem_ind = temp->index;
	if (firstelem != secondelem)
	{
		list->tab = secondelem;
		list->index = secondelem_ind;
		list = list->next;
		list->tab = firstelem;
		list->index = firstelem_ind;
	}
}

void	swap_a(t_tabl *list)
{
	if (!list)
		return ;
	if (get_stack_nb(list) < 2)
		return ;
	swap(list);
}

void	swap_b(t_tabl *list)
{
	if (!list)
		return ;
	if (get_stack_nb(list) < 2)
		return ;
	swap(list);
}

void	swap_swap(t_tabl *list_a, t_tabl *list_b)
{
	if (!list_a || !list_b)
		return ;
	if (get_stack_nb(list_a) < 2 || get_stack_nb(list_b) < 2)
		return ;
	swap(list_a);
	swap(list_b);
}
