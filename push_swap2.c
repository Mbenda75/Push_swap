/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:36 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/24 13:22:42 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack    *create_elem(char **tab, int i)
{
    t_stack *maillon;

    
    maillon = malloc(sizeof(maillon));

    
        maillon->nbr = atoi(tab[i]);
        maillon->next = NULL;

    return (maillon);
}

void    file_tab(t_lst *lst, char **av)
{
    int i;
    int j;
    char **tab;


    j = 0;
    i = 1;

    tab = ft_split(av[i], ' ');
    
    while(tab[j])
    {
        printf("tab[j]=== %s\n", tab[j]);
        file_stack_a(create_elem(tab, j));
        j++;
    }
}

t_lst   *init(char **tab)
{
    t_stack *pile_a;
    t_stack *pile_b;

    lst = malloc(sizeof(lst));
    
    lst->pile_a = NULL;
    lst->pile_b = NULL;
    file_tab(lst, tab);
    return (lst);
}

int main(int ac, char **av)
{
    init(av);
    return (0);
}