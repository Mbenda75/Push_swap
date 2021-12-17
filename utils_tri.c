/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:57:39 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 18:33:56 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	search_posmax(t_pile *pile_a)
{
	t_pile	*tmp;
	int		i;
	int		stock;

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
	int		i;
	int		stock;

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
