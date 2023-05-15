/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checking_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:13:33 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/11 18:36:32 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

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
				error_exit_normal();
			i++;
		}
		j++;
	}
}

void	check_white_space(int c, char **list)
{
	size_t	i;
	int		j;
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
			error_exit_normal();
		j++;
	}
}

int	check_is_nb(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	check_int(char *str)
{
	long long	temp;

	temp = ft_atoll(str);
	if (temp < -2147483648 || temp > 2147483647)
		return (0);
	return (1);
}

void	check_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	**splited;
	char	**temp;

	i = 1;
	j = 0;
	check_white_space(argc, argv);
	while (i < argc)
	{
		splited = ft_split(argv[i], '\"');
		temp = splited;
		while (*splited)
		{
			if (!check_is_nb(*splited) || !check_int(*splited))
				j++;
			free(*splited);
			splited++;
		}
		free(temp);
		i++;
	}
	error_exit_free(j);
	check_dup(argc, argv);
}
