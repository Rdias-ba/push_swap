/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_struct_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:07:34 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/11 18:37:01 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

void	parsing(int argc, char **argv, t_tabl **list_a)
{
	int		i;
	char	**splited;
	int		val_arg;
	char	**temp;

	i = 1;
	while (i < argc)
	{	
		splited = ft_split(argv[i], ' ');
		temp = splited;
		while (*splited)
		{
			val_arg = ft_atoi(*splited);
			creat_list_a(list_a, val_arg);
			free(*splited);
			splited++;
		}
		free(temp);
		i++;
	}
}

t_tabl	*lastcell(t_tabl *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	get_stack_nb(t_tabl *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
