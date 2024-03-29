/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:17:11 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/22 07:55:29 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_tabl *list)
{
	t_tabl	*temp;
	int		firstelem;
	int		secondelem;

	temp = list;
	if (!list)
		return ;
	firstelem = temp->tab;
	temp = temp->next;
	secondelem = temp->tab;
	if (firstelem != secondelem)
	{
		list->tab = secondelem;
		list = list->next;
		list->tab = firstelem;
	}
}

void	swap_a(t_tabl *list)
{
	if (!list)
		return ;
	if (get_stack_nb(list) < 2)
		return ;
	swap(list);
	ft_printf("sa\n");
}

void	swap_b(t_tabl *list)
{
	if (!list)
		return ;
	if (get_stack_nb(list) < 2)
		return ;
	swap(list);
	ft_printf("sb\n");
}

void	swap_swap(t_tabl *list_a, t_tabl *list_b)
{
	if (!list_a || !list_b)
		return ;
	if (get_stack_nb(list_a) < 2 || get_stack_nb(list_b) < 2)
		return ;
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
