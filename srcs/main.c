/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/02/16 16:36:55 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    (void)argc;
    check_int(argv);
    if (argc <= 2)
        return ;
    if (argc == 3)
        if_two(argv)
    create_struct_a(argc, argv);
      
}

t_list    *create_struct_a(int argc, char **argv)
{
    int         i;
    t_list      *val_a;
    t_list      *temp;

    i = 0;
    while (++i != argc)
    {
        temp = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(val_a, temp);            
    }
}

void    check_int(char **lst)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (lst[j])
    {
        j++;
        i = 0;
        if (lst[j][i] == '+' || lst[j][i] == '-')
                i++;
        while(lst[j][i])
        {
            if (lst[j][i] < '0' || ls > '9')
            {
                write(2, "ERROR\n", 6);
                exit(EXIT_FAILURE);
            }
            i++;
        }
    }
}

void    check_dup(t_list *lst)
{
    t_list     *temp;

    temp->next = content;
    while(*lst)
    {
        while(*temp)
        {
            if(lst == temp)
            {
                write(2, "ERROR\n", 6);
                exit(EXIT_FAILURE);
            }
            temp = temp->next;
        }
        lst = lst->next;
        temp = temp->lst;
    }
}

void    if_two(char **lst)
{
    int     temp;
    int     one;
    int     two;

    temp = 0;
    one = ft_atoi(lst[1]);
    two = ft_atoi(lst[2]);
    if (one > two)
        ft_printf("sa");
    exit(EXIT_SUCCESS);
}