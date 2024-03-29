/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:11:05 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/22 08:46:11 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_tabl **lista, t_tabl **listb)
{
	t_tabl	*temp;
	t_tabl	*copy;

	if (!*lista)
		return ;
	copy = newcell((*lista)->tab, (*lista)->index);
	temp = *lista;
	if (!(*listb))
		*listb = copy;
	else if (*listb)
		lst_addfront(listb, copy);
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
