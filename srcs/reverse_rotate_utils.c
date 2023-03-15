/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:23:26 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/14 22:29:49 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_tabl **list)
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

void	reverse_rotate_a(t_tabl **list)
{
	if (!*list)
		return ;
	if (get_stack_nb(*list) < 2)
		return ;
	reverse_rotate(list);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_tabl **list)
{
	if (!*list)
		return ;
	if (get_stack_nb(*list) < 2)
		return ;
	reverse_rotate(list);
	ft_printf("rrb\n");
}

void	reverse_rotate_rotate(t_tabl **list_a, t_tabl **list_b)
{
	if (!*list_a || !*list_b)
		return ;
	if (get_stack_nb(*list_a) < 2 || get_stack_nb(*list_b) < 2)
		return ;
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}
