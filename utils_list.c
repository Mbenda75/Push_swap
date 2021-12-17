/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:02:57 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 19:06:10 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_pile(t_pile *pile_a)
{
	int	i;

	i = 0;
	while (pile_a)
	{
		i++;
		pile_a = pile_a->next;
	}
	return (i);
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
	return (1);
}

t_pile	*lastnbr(t_pile *pile_a)
{
	while (pile_a->next)
	{
		pile_a = pile_a->next;
	}
	return (pile_a);
}
