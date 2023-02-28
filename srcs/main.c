/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/02/28 18:16:17 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_tabl	*ft_lstlast(t_tabl *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_tabl **lst, t_tabl *new)
{
	t_tabl	*end;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		end = ft_lstlast(*lst);
		end->next = new;
	}
}

t_tabl	*ft_lstnew(void *content)
{
	t_tabl	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->tab = content;
	lst->next = NULL;
	return (lst);
}

t_tabl	*create_struct_a(int argc, char **argv)
{
	int			i;
	t_tabl		*val_a;
	t_tabl		*temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(val_a, temp);
		i++;
	}
}

void	check_dup(int c, char **list)
{
	int	temp;
	int	i;
	int	j;

	j = 1;
	while (j < c)
	{
		temp = ft_atoi(list[j]);
		i = 1;
		while (i < c)
		{
			if (i == j && i < c - 1)
				i++;
			else if (i == j && i == c - 1)
				break ;
			if (temp == ft_atoi(list[i]))
			{
				ft_printf("There is duplicated numbers in the list");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

void	check_int(int c, char **list)
{
	int	i;
	int	j;

	j = 1;
	while (j < c)
	{
		i = 0;
		if (list[j][i] == '+' || list[j][i] == '-')
			i++;
		while (list[j][i])
		{
			if (ft_isdigit(list[j][i]) == 0)
			{
				ft_printf("Not all arguments are integer\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
	{
		ft_printf("Not enought arguments\n");
		return (0);
	}
	check_int(argc, argv);
	check_dup(argc, argv);
	return (0);
}
