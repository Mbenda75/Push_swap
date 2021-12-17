/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:36:10 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 18:14:44 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*push_b(t_pile *pile_a, t_pile *pile_b)
{
	if (!pile_b)
		pile_b = create_elem(pile_a->nbr);
	else
		pile_b = ft_pile_push_front(pile_b, pile_a->nbr);
	ft_putstr("pb\n");
	return (pile_b);
}

t_pile	*rotate_b(t_pile *pile_b)
{
	t_pile	*secondnbr;
	int		stock;

	if (len_pile(pile_b) == 1)
		return (pile_b);
	stock = pile_b->nbr;
	secondnbr = pile_b->next;
	ft_list_push_back(secondnbr, stock);
	pile_b = supprimer_nbrhead(pile_b);
	ft_putstr("rb\n");
	return (secondnbr);
}

t_pile	*rrotate_b(t_pile *pile_b)
{
	t_pile	*dernier;
	t_pile	*avantder;

	avantder = pile_b;
	dernier = lastnbr(pile_b);
	if (len_pile(pile_b) == 1)
		return (pile_b);
	else
		while (avantder->next->next)
			avantder = avantder->next;
	dernier->next = pile_b;
	avantder->next = NULL;
	ft_putstr("rrb\n");
	return (dernier);
}
