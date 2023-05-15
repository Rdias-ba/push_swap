/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:23:26 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/15 13:22:35 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_tabl **list)
{
	t_tabl	*temp;
	t_tabl	*copy;

	if (!*list)
		return ;
	temp = lastcell(*list);
	copy = newcell(temp->tab, temp->index);
	lst_addfront(list, copy);
	temp = *list;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

void	reverse_rotate_a(t_tabl **list)
{
	if (!*list)
		return ;
	if (get_stack_nb(*list) < 2)
		return ;
	reverse_rotate(list);
}

void	reverse_rotate_b(t_tabl **list)
{
	if (!*list)
		return ;
	if (get_stack_nb(*list) < 2)
		return ;
	reverse_rotate(list);
}

void	reverse_rotate_rotate(t_tabl **list_a, t_tabl **list_b)
{
	if (!*list_a || !*list_b)
		return ;
	if (get_stack_nb(*list_a) < 2 || get_stack_nb(*list_b) < 2)
		return ;
	reverse_rotate(list_a);
	reverse_rotate(list_b);
}
