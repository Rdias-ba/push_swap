/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:06 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/15 17:35:23 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_tabl	*newcell(int nb)
{
	t_tabl	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->tab = nb;
	lst->index = 0;
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

t_tabl	*create_struct_a(int argc, char **argv)
{
	int			i;
	t_tabl		*val_a;
	t_tabl		*temp;

	i = 1;
	val_a = newcell(ft_atoi(argv[i++]));
	while (i < argc)
	{
		temp = newcell(ft_atoi(argv[i]));
		lst_addback(&val_a, temp);
		i++;
	}
	return (val_a);
}
