/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:13:33 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/03 16:45:08 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_dup(int c, char **list)
{
	int	temp;
	int	i;
	int	j;

	j = 1;
	while (j < c)
	{
		temp = ft_atoi(list[j]);
		i = 1;
		while (i < c)
		{
			if (i == j && i < c - 1)
				i++;
			else if (i == j && i == c - 1)
				break ;
			if (temp == ft_atoi(list[i]))
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

void	check_int(int c, char **list)
{
	int	i;
	int	j;

	j = 1;
	while (j < c)
	{
		i = 0;
		if ((list[j][i] == '+' || list[j][i] == '-')
		&& ft_isdigit(list[j][i + 1]) == 1)
			i++;
		while (list[j][i])
		{
			if (ft_isdigit(list[j][i]) == 0)
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

int	check_is_sorted(t_tabl *list)
{
	int	i;

	i = list->tab;
	while (list->next)
	{
		list = list->next;
		if (i > list->tab)
			return (1);
		i = list->tab;
	}
	return (0);
}
