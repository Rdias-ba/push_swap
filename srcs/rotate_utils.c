/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:07 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/14 18:38:07 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_tabl **list)
{
	t_tabl	*temp;

	temp = *list;
	if (!*list)
		return ;
	lst_addback(list, newcell((*list)->tab));
	*list = (*list)->next;
	free(temp);
}

void	rotate_a(t_tabl **list)
{
	if (!*list)
		return ;
	if (get_stack_nb(*list) < 2)
		return ;
	rotate(list);
	ft_printf("ra\n");
}

void	rotate_b(t_tabl **list)
{
	if (!*list)
		return ;
	if (get_stack_nb(*list) < 2)
		return ;
	rotate(list);
	ft_printf("rb\n");
}

void	rotate_rotate(t_tabl **list_a, t_tabl **list_b)
{
	if (!*list_a || !*list_b)
		return ;
	if (get_stack_nb(*list_a) < 2 || get_stack_nb(*list_b) < 2)
		return ;
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}
