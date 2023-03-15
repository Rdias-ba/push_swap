/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:07:34 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/03/14 22:29:50 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			s;
	long long	total;

	total = 0;
	s = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total = total * 10 + (nptr[i] - 48);
		i++;
	}
	return (total * s);
}

void	printlst(t_tabl *lsta, t_tabl *lstb)
{
	while (lsta || lstb)
	{
		if (lsta && lstb)
		{
			ft_printf("%d    %d\n", lsta->tab, lstb->tab);
			lsta = lsta->next;
			lstb = lstb->next;
		}
		else if (lsta)
		{
			ft_printf("%d     \n", lsta->tab);
			lsta = lsta->next;
		}
		else if (lstb)
		{
			ft_printf("     %d\n", lstb->tab);
			lstb = lstb->next;
		}
	}
	ft_printf("------\n");
	ft_printf("a    b\n");
}

t_tabl	*lastcell(t_tabl *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	get_at(t_tabl *list, int pos)
{
	int	i;

	i = 0;
	while (i < pos && list->next)
	{
		list = list->next;
		i++;
	}
	return (list->tab);
}

int	get_stack_nb(t_tabl *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
