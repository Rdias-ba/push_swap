/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:58:21 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/15 18:25:44 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct s_tabl
{
	int					tab;
	int					index;
	struct s_tabl		*next;
}						t_tabl;

void		check_params(int c, char **list);
void		arg_indexer(t_tabl **list_a);
void		printlst(t_tabl *lsta, t_tabl *lstb);
long long	ft_atoll(const char *nptr);
t_tabl		*lastcell(t_tabl *lst);
int			identify_case(t_tabl *list_a);
void		lst_addback(t_tabl **lst, t_tabl *new);
void		lst_addfront(t_tabl **lst, t_tabl *new);
int			get_at(t_tabl	*list, int pos);
t_tabl		*newcell(int nb);
t_tabl		*create_struct_a(int argc, char **argv);
int			check_is_sorted(t_tabl *list);
int			get_stack_nb(t_tabl *list);
void		swap_a(t_tabl *list);
void		swap_b(t_tabl *list);
void		swap_swap(t_tabl *list_a, t_tabl *list_b);
void		rotate_a(t_tabl **list);
void		rotate_b(t_tabl **list);
void		rotate_rotate(t_tabl **list_a, t_tabl **list_b);
void		reverse_rotate_a(t_tabl **list);
void		reverse_rotate_b(t_tabl **list);
void		reverse_rotate_rotate(t_tabl **list_a, t_tabl **list_b);
void		push_a(t_tabl **lista, t_tabl **listb);
void		push_b(t_tabl **lista, t_tabl **listb);
void		push_b_lowest(t_tabl **list_a, t_tabl **list_b);
void		push_b_before_lowest(t_tabl **list_a, t_tabl **list_b);
void		sorting_low(t_tabl **list_a, t_tabl **list_b);
void		sort_tab(t_tabl **list_a, t_tabl **list_b);
void		sorting_big(t_tabl **list_a, t_tabl **list_b);

#endif