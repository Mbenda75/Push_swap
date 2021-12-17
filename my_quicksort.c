/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:50:22 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 18:49:50 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_pile *pile, int *tab, int size)
{
	int	index;
	int	median;

	tab = tab_int(pile, size);
	tab = value_sort(tab, size);
	if (size >= 500)
		index = size / 7;
	else
		index = size / 5;
	median = tab[index];
	free(tab);
	return (median);
}

t_pile	*push_lessmedian(t_pile *pile_a, t_pile *pile_b, int size)
{
	int		med;
	int		*tab;
	t_pile	*tmp;

	tab = NULL;
	while (pile_a)
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
				tmp = rotate_a(tmp);
			size--;
		}
		pile_a = tmp;
		size = len_pile(pile_a);
	}
	pile_a = max_sort_top(pile_a, pile_b);
	return (pile_a);
}
