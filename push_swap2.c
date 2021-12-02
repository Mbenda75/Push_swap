/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:36 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/02 13:55:02 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int len_pile(t_pile *pile_a)
{
    int i;

    i = 0;
    while (pile_a)
    {
        i++;
        pile_a = pile_a->next;
    }
    return(i);
}

t_pile    *create_elem(int nbr)
{
    t_pile *elem;
    
    elem = malloc(sizeof(t_pile));

    elem->nbr = nbr;
    elem->next = NULL;
    return (elem);
}

void    print_list(t_pile *pile_a)
{
    while(pile_a)
    {
        printf("nb ==== %d\n", pile_a->nbr);
        pile_a= pile_a->next;
    }
        
}

t_pile   *file_tab(char **av)
{
    int i;
    int j;
    t_pile *tmp;
    t_pile *pile_a;

    pile_a = NULL;
    j = 0;
    i = 1;
    check_str(av[i]);
    av = ft_split(av[i], ' ');
    while(av[j])
    {
        if(!pile_a)
        {
            pile_a = create_elem(atoi(av[j]));
            tmp = pile_a; 
        }
        else 
        {
            tmp->next = create_elem(atoi(av[j]));
            tmp = tmp->next;
        }
        j++;
    }
    return pile_a;
}

t_pile   *init(char **tab)
{
    t_pile *pile_a;
    t_pile *pile_b;
    int size;
     
    pile_a = file_tab(tab);
    pile_b = NULL;
    print_list(pile_a);
    size = len_pile(pile_a);
    return (pile_a);
}

int main(int ac, char **av)
{
    t_pile *pile_a;
    pile_a = init(av);
    check_doublon(pile_a);
    pile_a = tri_three(pile_a);
    print_list(pile_a);
    return (0);
}