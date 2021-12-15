/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:50:24 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/14 19:11:14 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_swap(long *a, long *b)
{
	long c;

	c = *a;
	*a = *b;
	*b = c;
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

t_pile	*ajouter_nbrhead(t_pile *liste, int valeur)
{
	t_pile	*new_nbr;

	new_nbr = malloc(sizeof(t_pile));
	new_nbr->nbr = valeur;
	new_nbr->next = liste;
	return (new_nbr);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	if (nbr <= 9)
	{
		ft_putchar((nbr % 10) + 48);
	}
}
