/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:50:22 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/15 21:03:19 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *tab_int(t_pile *pile_a, int size)
{
    int i;
    int *tab;
    
    i = 0;
    tab =  malloc(sizeof(int) * size +1 );
    while(i < size)
    {
        tab[i] = pile_a->nbr;
        i++;
        pile_a = pile_a->next;
    }
    return (tab);
}

int    *value_sort(int *tab, int len)
{
    long    tmp;
    int        posnbr;

    tmp = 0;
    posnbr = 0;
    while (posnbr < len - 1)
    {
        if (tab[posnbr] <= tab[posnbr + 1])
            posnbr++;
        else
        {
            tmp = tab[posnbr];
            tab[posnbr] = tab[posnbr + 1];
            tab[posnbr + 1] = tmp;
            posnbr = 0;
        }
    }
    return (tab);
}

t_pile  *max_sort_top(t_pile *pile_a, t_pile *pile_b)
{
	int	posmin;
	int	size;
    while(pile_a)
    {
        size = len_pile(pile_a);
        posmin = search_posmin(pile_a);
        if (posmin <= size / 2)
        {
            while (posmin && posmin != 1)
            {
                pile_a = rotate_a(pile_a);
                posmin--;
            }
        }
        else if (posmin != 1)
        {
            while (posmin <= size)
            {
                pile_a = rrotate_a(pile_a);
                posmin++;
            }
        }
        pile_b = push_b(pile_a, pile_b);
        pile_a = supprimer_nbrhead(pile_a);
    }
	return (pile_b);
}

t_pile  *last_sort(t_pile *pile_a, t_pile *pile_b)
{
    int size;
    size = len_pile(pile_a);
    while (size--)
    {
        pile_b = push_a(pile_b, pile_a);
        pile_a = supprimer_nbrhead(pile_a);
    }
    return (pile_b);
}

int get_median(t_pile *pile, int *tab, int size)
{
    int med;
    
    tab = tab_int(pile, size);
	tab = value_sort(tab, size);
    med = size / 7;
    return(tab[med]);
}

t_pile    *push_lessmedian(t_pile *pile_a, t_pile *pile_b, int size)
{
    int med;
    int *tab = NULL;
    t_pile  *tmp;
    while(pile_a)
    {
        tmp = pile_a;
        med = get_median(tmp, tab, size);
        while (size)
        {
            if (tmp->nbr <= med)
            {
                pile_b = push_b(tmp, pile_b);
                tmp = supprimer_nbrhead(tmp);
            }
            else
                tmp = rrotate_a(tmp);
            size--; 
        }
        pile_a = tmp;
        size = len_pile(pile_a);
    }
     while(pile_b)
    {
        size = len_pile(pile_b);
        tmp = pile_b;
        med = get_median(tmp, tab, size);
        while (size)
        {
            if (tmp->nbr >= med)
            {
                pile_a = push_a(pile_a, tmp);
                tmp = tmp->next;
            }
            else
                tmp = rrotate_b(tmp);
            size--; 
        }
        pile_b = tmp;
    }
    //print_list(pile_a);
    //printf("NON------------------\n");
 
    pile_b = max_sort_top(pile_a, pile_b);
     //print_list(pile_b);
  // printf("yes------------------\n");
    pile_a = last_sort(pile_b, pile_a);
    //print_list(pile_a);
    return (pile_b);
}
