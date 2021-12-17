/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:36:10 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 18:48:01 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*free_stack(t_pile *pile_a)
{
	t_pile	*nbr;

	while (pile_a)
	{
		nbr = pile_a;
		pile_a = pile_a->next;
		free(nbr);
	}
	return (pile_a);
}

t_pile	*create_elem(int nbr)
{
	t_pile	*elem;

	elem = malloc(sizeof(t_pile));
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}

t_pile	*ft_list_push_back(t_pile *pile_a, int nbr)
{
	t_pile	*list;

	list = pile_a;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = create_elem(nbr);
	}
	return (list);
}

t_pile	*ft_pile_push_front(t_pile *begin, int data)
{
	t_pile	*push;

	if (begin)
	{
		push = create_elem(data);
		push->next = begin;
		begin = push;
	}
	return (push);
}

t_pile	*supprimer_nbrhead(t_pile *pile_a)
{
	t_pile	*new_pile;

	if (pile_a != NULL)
	{
		new_pile = pile_a->next;
		free(pile_a);
		return (new_pile);
	}
	else
	{
		return (NULL);
	}
}
