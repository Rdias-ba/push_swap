/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:58:21 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/03 16:45:54 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct s_tabl
{
	int				tab;
	struct s_tabl	*next;
}					t_tabl;

void	check_dup(int c, char **list);
void	check_int(int c, char **list);
void	printlst(t_tabl *lsta, t_tabl *lstb);
t_tabl	*lastcell(t_tabl *lst);
void	lst_addback(t_tabl **lst, t_tabl *new);
void	lst_addfront(t_tabl **lst, t_tabl *new);
int		get_at(t_tabl	*list, int pos);
t_tabl	*newcell(int nb);
t_tabl	*create_struct_a(int argc, char **argv);
void	swap(t_tabl *list);
void	reverse_rotate(t_tabl **list);
void	rotate(t_tabl **list);
void	push(t_tabl **lista, t_tabl **listb);
int		check_is_sorted(t_tabl *list);

#endif