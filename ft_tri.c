/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:44 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/02 13:31:33 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile  *tri_three(t_pile *pile_a)
{
    if (pile_a->nbr > pile_a->next->nbr && pile_a->next->next->nbr > pile_a->nbr)
        pile_a = swap_a(pile_a, 0);
    else if (pile_a->nbr > pile_a->next->nbr && pile_a->next->nbr > pile_a->next->next->nbr)
    {
        pile_a = swap_a(pile_a, 0);
        pile_a = rrotate_a(pile_a);
    } 
    else if (pile_a->nbr > pile_a->next->nbr && pile_a->next->nbr < pile_a->next->next->nbr)
        pile_a = rotate_a(pile_a);
    else if (pile_a->nbr < pile_a->next->nbr && pile_a->nbr < pile_a->next->next->nbr && pile_a->next->nbr > pile_a->next->next->nbr)
    {
        pile_a = swap_a(pile_a, 0);
        pile_a = rotate_a(pile_a);
    }
    else if (pile_a->nbr < pile_a->next->nbr && pile_a->next->nbr > pile_a->next->next->nbr)
        pile_a = rrotate_a(pile_a);
}


/* t_pile  *tri_five(t_pile *pile_a, t_pile *pile_b)
{
    t_pile *copy_a;
    t_pile *copy_b;


    copy_b = pile_b;
    copy_a = pile_a;

    while(copy_a)
    
} */