/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:48:13 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/09 23:14:53 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit_normal(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	error_exit_free(int i)
{
	if (i > 0)
		error_exit_normal();
}

void	free_list(t_tabl **list_a, t_tabl **list_b)
{
	t_tabl	*temp;

	while (*list_a)
	{
		temp = (*list_a)->next;
		free(*list_a);
		*list_a = temp;
	}
	*list_a = NULL;
	while (*list_b)
	{
		temp = (*list_b)->next;
		free(*list_b);
		*list_b = temp;
	}
	*list_b = NULL;
}

void	free_split(char **splited)
{
	while (*splited)
	{
		free(*splited);
		splited++;
	}
}

void	free_arg_alt(int i, char *args)
{
	if (i > 0)
		free(args);
}
