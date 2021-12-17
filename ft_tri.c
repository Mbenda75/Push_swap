/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:44 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 18:18:05 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*tri_for5(t_pile *pile_a, t_pile *pile_b)
{
	pile_a = min_totop(pile_a);
	pile_b = push_b(pile_a, pile_b);
	pile_a = supprimer_nbrhead(pile_a);
	pile_a = max_totop(pile_a);
	pile_b = push_b(pile_a, pile_b);
	pile_a = supprimer_nbrhead(pile_a);
	pile_a = tri_for3(pile_a);
	pile_a = push_a(pile_a, pile_b);
	pile_b = supprimer_nbrhead(pile_b);
	pile_a = rotate_a(pile_a);
	pile_a = push_a(pile_a, pile_b);
	pile_b = supprimer_nbrhead(pile_b);
	return (pile_a);
}

t_pile	*tri_3fornorm(t_pile	*pile_a)
{
	if (pile_a->nbr > pile_a->next->nbr
		&& pile_a->next->nbr < pile_a->next->next->nbr)
	{
		pile_a = rotate_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr < pile_a->next->nbr
		&& pile_a->nbr < pile_a->next->next->nbr
		&&pile_a->next->nbr > pile_a->next->next->nbr)
	{
		pile_a = swap_a(pile_a);
		pile_a = rotate_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr < pile_a->next->nbr
		&& pile_a->next->nbr > pile_a->next->next->nbr)
	{
		pile_a = rrotate_a(pile_a);
		return (pile_a);
	}
	return (pile_a);
}

t_pile	*tri_for3(t_pile *pile_a)
{
	if (pile_a->nbr > pile_a->next->nbr
		&& pile_a->next->next->nbr > pile_a->nbr)
	{
		pile_a = swap_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr > pile_a->next->nbr
		&& pile_a->next->nbr > pile_a->next->next->nbr)
	{
		pile_a = swap_a(pile_a);
		pile_a = rrotate_a(pile_a);
		return (pile_a);
	}
	pile_a = tri_3fornorm(pile_a);
	return (pile_a);
}

t_pile	*tri_2(t_pile *pile_a)
{
	if (pile_a->nbr > pile_a->next->nbr)
		pile_a = swap_a(pile_a);
	return (pile_a);
}
