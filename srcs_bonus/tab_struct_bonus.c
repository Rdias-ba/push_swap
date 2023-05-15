/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_struct_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:06 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/11 18:37:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

void	lst_addback(t_tabl **lst, t_tabl *new)
{
	t_tabl	*end;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		end = lastcell(*lst);
		end->next = new;
	}
}

void	lst_addfront(t_tabl **lst, t_tabl *new)
{
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	else if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_tabl	*newcell(int nb, int index)
{
	t_tabl	*lst;

	lst = malloc(sizeof(t_tabl));
	if (!lst)
		error_exit_normal();
	lst->tab = nb;
	lst->index = index;
	lst->next = NULL;
	return (lst);
}

void	arg_indexer(t_tabl **list_a)
{
	t_tabl	*temp;
	t_tabl	*temp_2;

	temp = (*list_a);
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
	temp = (*list_a);
	while (temp)
	{
		temp_2 = (*list_a);
		while (temp_2)
		{
			if (temp->tab > temp_2->tab)
				temp->index++;
			temp_2 = temp_2->next;
		}
		temp = temp->next;
	}
}

void	creat_list_a(t_tabl **list_a, int arg)
{
	t_tabl	*temp;

	temp = newcell(arg, 0);
	lst_addback(list_a, temp);
}
