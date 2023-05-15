/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:39:39 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/15 15:50:55 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/push_swap_bonus.h"

static void	input_from_read(char *buf, t_tabl **list_a, t_tabl **list_b)
{
	if (buf[0] == 'p' && buf[1] == 'a')
		push_a(list_a, list_b);
	if (buf[0] == 'p' && buf[1] == 'b')
		push_b(list_a, list_b);
	if (buf[0] == 's' && buf[1] == 'a')
		swap_a(*list_a);
	if (buf[0] == 's' && buf[1] == 'b')
		swap_b(*list_b);
	if (buf[0] == 's' && buf[1] == 's')
		swap_swap(*list_a, *list_b);
	if (buf[0] == 'r' && buf[1] == 'a')
		rotate_a(list_a);
	if (buf[0] == 'r' && buf[1] == 'b')
		rotate_b(list_b);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		rotate_rotate(list_a, list_b);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a')
		reverse_rotate_a(list_a);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b')
		reverse_rotate_b(list_b);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r')
		reverse_rotate_rotate(list_a, list_b);
}

void	read_from_stdin(t_tabl **list_a, t_tabl **list_b)
{
	char	*buf;

	buf = malloc(sizeof(char) * 5);
	read(1, buf, 5);
	while (buf[0] && buf[0] != '\n')
	{
		input_from_read(buf, list_a, list_b);
		read(1, buf, 5);
	}
	free(buf);
}
