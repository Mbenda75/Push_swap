/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:44 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/15 19:14:08 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_posmax(t_pile *pile_a)
{
	t_pile	*tmp;
	int	i;
	int	stock;

	tmp = pile_a;
	i = 1;
	stock = pile_a->nbr;
	while (pile_a)
	{
		if (pile_a->nbr > stock)
		{
			stock = pile_a->nbr;
		}
		pile_a = pile_a->next;
	}
	while (tmp->nbr != stock)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	search_posmin(t_pile *pile_a)
{
	t_pile	*tmp;
	int	i;
	int	stock;

	i = 1;
	tmp = pile_a;
	stock = pile_a->nbr;
	while (pile_a)
	{
		if (pile_a->nbr < stock)
		{
			stock = pile_a->nbr;
		}
		pile_a = pile_a->next;
	}
	while (tmp->nbr != stock)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_pile	*max_totop(t_pile *pile_a)
{
	int	posmax;
	int	size;

	size = len_pile(pile_a);
	posmax = search_posmax(pile_a);
	if (posmax <= size / 2)
	{
		if (posmax == 2)
			pile_a = swap_a(pile_a);
	}
	else if (posmax != 1)
	{
		while (posmax <= size)
		{
			pile_a = rrotate_a(pile_a);
			posmax++;
		}
	}
	return (pile_a);
}

t_pile	*min_totop(t_pile *pile_a)
{
	int	posmin;
	int	size;


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
	return (pile_a);
}


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

t_pile	*tri_for3(t_pile *pile_a)
{
	if (pile_a->nbr > pile_a->next->nbr && pile_a->next->next->nbr > pile_a->nbr)
	{
		pile_a = swap_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr > pile_a->next->nbr && pile_a->next->nbr > pile_a->next->next->nbr)
	{
		pile_a = swap_a(pile_a);
		pile_a = rrotate_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr > pile_a->next->nbr && pile_a->next->nbr < pile_a->next->next->nbr)
	{
		pile_a = rotate_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr < pile_a->next->nbr && pile_a->nbr < pile_a->next->next->nbr
		&& pile_a->next->nbr > pile_a->next->next->nbr)
	{
		pile_a = swap_a(pile_a);
		pile_a = rotate_a(pile_a);
		return (pile_a);
	}
	else if (pile_a->nbr < pile_a->next->nbr && pile_a->next->nbr > pile_a->next->next->nbr)
	{
		
		pile_a = rrotate_a(pile_a);
		return (pile_a);
	}
	return (pile_a);
}

t_pile	*tri_2(t_pile *pile_a)
{
	if (pile_a->nbr > pile_a->next->nbr)
		pile_a = swap_a(pile_a);
	return (pile_a);
}

int	check_sort(t_pile *pile_a)
{
	while (pile_a->next)
	{
		if (pile_a->nbr < pile_a->next->nbr && pile_a->next != NULL)
			pile_a = pile_a->next;
		else
			return (0);
	}
	exit (0);
}