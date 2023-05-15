/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:01:07 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/15 15:35:30 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

int	check_is_sorted(t_tabl *list)
{
	int	i;

	i = list->index;
	if (i != 0)
		return (0);
	if (!list->next && list)
		return (1);
	while (list->next)
	{
		list = list->next;
		if (i > list->index)
			return (0);
		i = list->index;
	}
	return (1);
}
