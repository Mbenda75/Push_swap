/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:05:25 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 18:05:26 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*swap_a(t_pile *pile_a)
{
	if (pile_a->nbr && pile_a->next->nbr)
	{
		ft_swap(&(pile_a->nbr), &(pile_a->next->nbr));
	}
	ft_putstr("sa\n");
	return (pile_a);
}

t_pile	*push_a(t_pile *pile_a, t_pile *pile_b)
{
	if (!pile_a)
		pile_a = create_elem(pile_b->nbr);
	else
		pile_a = ft_pile_push_front(pile_a, pile_b->nbr);
	ft_putstr("pa\n");
	return (pile_a);
}

t_pile	*rotate_a(t_pile *pile_a)
{
	int		stock;
	t_pile	*secondnbr;

	if (len_pile(pile_a) == 1)
		return (pile_a);
	stock = pile_a->nbr;
	secondnbr = pile_a->next;
	ft_list_push_back(secondnbr, stock);
	pile_a = supprimer_nbrhead(pile_a);
	ft_putstr("ra\n");
	return (secondnbr);
}

t_pile	*rrotate_a(t_pile *pile_a)
{
	t_pile	*dernier;
	t_pile	*avantder;

	avantder = pile_a;
	dernier = lastnbr(pile_a);
	if (len_pile(pile_a) == 1)
		return (pile_a);
	else
		while (avantder->next->next)
			avantder = avantder->next;
	dernier->next = pile_a;
	avantder->next = NULL;
	ft_putstr("rra\n");
	return (dernier);
}
