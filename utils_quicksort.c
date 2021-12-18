/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:49:00 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/18 17:02:21 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_int(t_pile *pile_a, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size + 1);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = pile_a->nbr;
		i++;
		pile_a = pile_a->next;
	}
	return (tab);
}

int	*value_sort(int *tab, int len)
{
	long	tmp;
	int		posnbr;

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

t_pile	*max_sort_top2(t_pile *pile_b, int posmax, int size)
{
	if (posmax <= size / 2)
	{
		while (posmax && posmax != 1)
		{
			pile_b = rotate_b(pile_b);
			posmax--;
		}
	}
	else if (posmax != 1)
	{
		while (posmax <= size)
		{
			pile_b = rrotate_b(pile_b);
			posmax++;
		}
	}
	return (pile_b);
}

t_pile	*max_sort_top(t_pile *pile_a, t_pile *pile_b)
{
	int	posmax;
	int	size;

	while (pile_b)
	{
		size = len_pile(pile_b);
		posmax = search_posmax(pile_b);
		pile_b = max_sort_top2(pile_b, posmax, size);
		pile_a = push_a(pile_a, pile_b);
		pile_b = supprimer_nbrhead(pile_b);
	}
	return (pile_a);
}
