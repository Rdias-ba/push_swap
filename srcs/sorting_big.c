/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:52:59 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/11 17:25:52 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	get_max_bits(t_tabl *list)
{
	t_tabl		*temp;
	int			max;
	int			max_bits;

	temp = list;
	max = temp->index;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sorting_big(t_tabl **list_a, t_tabl **list_b)
{
	t_tabl	*temp;
	int		i;
	int		j;
	int		max_bits;
	int		size;

	i = 0;
	max_bits = get_max_bits(*list_a);
	size = get_stack_nb(*list_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp = (*list_a);
			if (((temp->index >> i) & 1) == 1)
				rotate_a(list_a);
			else
				push_b(list_a, list_b);
		}
		while (get_stack_nb(*list_b) > 0)
			push_a(list_a, list_b);
		i++;
	}
}
