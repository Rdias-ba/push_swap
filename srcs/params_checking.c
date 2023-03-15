/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:13:33 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/14 22:29:47 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_dup(int c, char **list)
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

static void	check_white_space(int c, char **list)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 1;
	while (j < c)
	{
		temp = list[j];
		while (*temp)
		{
			if (*temp == ' ' || *temp == '\n' || *temp == '\r'
				|| *temp == '\t' || *temp == '\v' || *temp == '\f')
				i++;
			temp++;
		}
		if (i == ft_strlen(list[j]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

static void	check_is_nb(int c, char **list)
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

static void	check_int(int c, char **list)
{
	long long	temp;
	int			j;

	j = 1;
	while (j < c)
	{
		temp = ft_atoll(list[j]);
		if (temp < -2147483648 || temp > 2147483647)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_params(int c, char **list)
{
	check_white_space(c, list);
	check_is_nb(c, list);
	check_int(c, list);
	check_dup(c, list);
}
