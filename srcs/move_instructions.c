/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:11:05 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/03 16:12:42 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_tabl *list)
{
	int	firstelem;
	int	secondelem;

	if (!list)
		return ;
	firstelem = list->tab;
	secondelem = get_at(list, 1);
	if (firstelem != secondelem)
	{
		list->tab = secondelem;
		list = list->next;
		list->tab = firstelem;
	}
}

void	reverse_rotate(t_tabl **list)
{
	t_tabl	*temp;
	int		lastnb;

	temp = lastcell(*list);
	if (!*list)
		return ;
	lastnb = temp->tab;
	lst_addfront(list, newcell(lastnb));
	temp = *list;
	while (temp->next->next)
		temp = temp->next;

	free(temp->next);
	temp->next = NULL;
}

void	rotate(t_tabl **list)
{
	t_tabl	*temp;

	temp = *list;
	if (!*list)
		return ;
	lst_addback(list, newcell((*list)->tab));
	*list = (*list)->next;
	free(temp);
}

void	push(t_tabl **lista, t_tabl **listb)
{
	t_tabl	*temp;

	temp = *lista;
	if (!*lista)
		return ;
	if (!(*listb))
	{
		*listb = newcell((*lista)->tab);
	}
	else if (*listb)
	{
		lst_addfront(listb, newcell((*lista)->tab));
	}
	*lista = (*lista)->next;
	free(temp);
}
