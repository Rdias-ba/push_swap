/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/15 19:33:01 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_tabl	*tab_a;
	t_tabl	*tab_b;

	if (argc <= 1)
		return (0);
	check_params(argc, argv);
	tab_a = create_struct_a(argc, argv);
	arg_indexer(&tab_a);
	sort_tab(&tab_a, &tab_b);
	return (0);
}
