/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checking_one_arg_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:27:01 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/11 18:36:36 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

int	check_white_space_one_arg(int c, char **args)
{
	size_t	i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (j < c)
	{
		temp = args[j];
		while (*temp)
		{
			if (*temp == ' ' || *temp == '\n' || *temp == '\r'
				|| *temp == '\t' || *temp == '\v' || *temp == '\f')
				i++;
			temp++;
		}
		if (i == ft_strlen(args[j]))
			return (0);
		j++;
	}
	return (1);
}

static int	check_dup_alt(int c, char **list)
{
	int	temp;
	int	i;
	int	j;

	j = 0;
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
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_dup_one_arg(int c, char *list)
{
	int		i;
	char	**splited;
	char	**temp;

	i = 0;
	splited = ft_split(list, ' ');
	temp = splited;
	if (!check_dup_alt(c, splited))
		i++;
	free_split(splited);
	free(temp);
	return (i);
}
