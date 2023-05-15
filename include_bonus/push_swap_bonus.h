/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:58:21 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/15 15:10:57 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct s_tabl
{
	int					tab;
	int					index;
	struct s_tabl		*next;
}						t_tabl;

void	params_checking_one_arg(char **argv, t_tabl **list_a);
void	check_dup(int c, char **list);
void	check_white_space(int c, char **list);
int		check_is_nb(char *str);
int		check_int(char *str);
void	check_params(int argc, char **argv);
int		check_white_space_one_arg(int c, char **args);
int		check_dup_one_arg(int c, char *list);
void	error_exit_normal(void);
void	error_exit_free(int i);
void	free_list(t_tabl **list_a, t_tabl **list_b);
void	free_split(char **splited);
void	lst_addback(t_tabl **lst, t_tabl *new);
void	lst_addfront(t_tabl **lst, t_tabl *new);
t_tabl	*newcell(int nb, int index);
void	arg_indexer(t_tabl **list_a);
void	creat_list_a(t_tabl **list_a, int arg);
void	parsing(int argc, char **argv, t_tabl **list_a);
t_tabl	*lastcell(t_tabl *lst);
int		get_stack_nb(t_tabl *list);
void	push_a(t_tabl **lista, t_tabl **listb);
void	push_b(t_tabl **lista, t_tabl **listb);
void	read_from_stdin(t_tabl **list_a, t_tabl **list_b);
int		check_is_sorted(t_tabl *list_a);
void	swap_a(t_tabl *list);
void	swap_b(t_tabl *list);
void	swap_swap(t_tabl *list_a, t_tabl *list_b);
void	reverse_rotate_a(t_tabl **list);
void	reverse_rotate_b(t_tabl **list);
void	reverse_rotate_rotate(t_tabl **list_a, t_tabl **list_b);
void	rotate_a(t_tabl **list);
void	rotate_b(t_tabl **list);
void	rotate_rotate(t_tabl **list_a, t_tabl **list_b);

#endif