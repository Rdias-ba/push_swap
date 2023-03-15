/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:11:05 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/14 18:39:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_tabl **lista, t_tabl **listb)
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

void	push_a(t_tabl **lista, t_tabl **listb)
{
	if (!*listb)
		return ;
	push(listb, lista);
	ft_printf("pa\n");
}

void	push_b(t_tabl **lista, t_tabl **listb)
{
	if (!*lista)
		return ;
	push(lista, listb);
	ft_printf("pb\n");
}
