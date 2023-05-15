/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:28:15 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/11 17:28:09 by rdias-ba         ###   ########.fr       */
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
	int		i;
	int		args_len;
	char	*str;

	args_len = ft_strlen(args);
	str = malloc(sizeof(char) * args_len);
	i = 0;
	if (!str)
		error_exit_normal();
	while (args[i])
	{
		str[i] = args[i];
		i++;
	}
	i = 1;
	if (args[0] == '{' && args[args_len - 1] == '}')
	{
		free(str);
		str = ft_strtrim(args, "{}");
		return (str);
	}
	else if (args[0] == '{' || args[args_len - 1] == '}')
		error_exit_normal();
	return (str);
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
	args = brackets_check(args);
	splited = ft_split(args, ' ');
	temp = splited;
	args_count = counting_args(splited);
	free_split(splited);
	free(temp);
	if (args_count < 2)
	{
		i++;
	}
	if (check_params_one_arg(args_count, args) > 0)
	{
		free(args);
		error_exit_normal();
	}
	parsing_one_arg(args, list_a);
	free(args);
}
