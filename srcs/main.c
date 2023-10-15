/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/10/15 23:41:32 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	sort_tab(&tab_a, &tab_b);
	free_list(&tab_a, &tab_b);
	return (0);
}
