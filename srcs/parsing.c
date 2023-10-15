/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:28:15 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/10/16 00:12:48 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	counting_args(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		i++;
	}
	return (i);
}

static char	*brackets_check(char *args)
{
	int		args_len;

	args_len = ft_strlen(args);
	if (args[0] == '{' && args[args_len - 1] == '}')
	{
		args = ft_strtrim(args, "{}");
		return (args);
	}
	else if (args[0] == '{' || args[args_len - 1] == '}' || args[0] == 0)
		error_exit_normal();
	return (args);
}

static int	check_params_one_arg(int argc, char *argv)
{
	int		j;
	char	**splited;
	char	**temp;

	j = 0;
	splited = ft_split(argv, ' ');
	if (!check_white_space_one_arg(argc, splited))
		j++;
	temp = splited;
	while (*splited)
	{
		if (!check_is_nb(*splited) || !check_int(*splited))
			j++;
		free(*splited);
		splited++;
	}
	free(temp);
	j += check_dup_one_arg(argc, argv);
	return (j);
}

static void	parsing_one_arg(char *argv, t_tabl **list_a)
{
	char	**splited;
	int		val_arg;
	char	**temp;

	splited = ft_split(argv, ' ');
	temp = splited;
	while (*splited)
	{
		val_arg = ft_atoi(*splited);
		creat_list_a(list_a, val_arg);
		free(*splited);
		splited++;
	}
	free(temp);
}

void	params_checking_one_arg(char **argv, t_tabl **list_a)
{
	int		i;
	int		args_count;
	char	*args;
	char	**splited;
	char	**temp;

	i = 0;
	args = argv[1];
	if (args[0] == '{' && args[ft_strlen(args) - 1] == '}')
		i = 1;
	args = brackets_check(args);
	splited = ft_split(args, ' ');
	temp = splited;
	args_count = counting_args(splited);
	free_split(splited);
	free(temp);
	if (check_params_one_arg(args_count, args) > 0)
	{
		if (i == 1)
			free(args);
		error_exit_normal();
	}
	parsing_one_arg(args, list_a);
	if (i == 1)
		free(args);
}
