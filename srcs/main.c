/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/03 16:49:17 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_tabl	*tab_a;
	t_tabl	*tab_b;

	if (argc <= 1)
	{
		return (0);
	}
	check_int(argc, argv);
	check_dup(argc, argv);
	tab_a = create_struct_a(argc, argv);
	tab_b = NULL;
	if (check_is_sorted(tab_a) == 1)
		return (0);
	return (0);
}
