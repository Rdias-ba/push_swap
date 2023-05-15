/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:49:33 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/15 17:51:16 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_tabl	*tab_a;
	t_tabl	*tab_b;

	tab_a = NULL;
	tab_b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		params_checking_one_arg(argv, &tab_a);
	else
	{
		check_params(argc, argv);
		parsing(argc, argv, &tab_a);
	}
	arg_indexer(&tab_a);
	read_from_stdin(&tab_a, &tab_b);
	if (!tab_a)
		ft_printf("KO\n");
	else if (check_is_sorted(tab_a) && !tab_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&tab_a, &tab_b);
	return (0);
}
