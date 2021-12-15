/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:36 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/15 20:46:03 by benmoham         ###   ########.fr       */
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

t_pile	*lastnbr(t_pile *pile_a)
{
	while (pile_a->next)
	{
		pile_a = pile_a->next;
	}
	return (pile_a);
}

t_pile	*file_tab(char **av)
{
	int	j;
	t_pile	*tmp;
	t_pile	*pile_a;
	char **tab;

	//tab = ft_split(av[1], ' ');	
	pile_a = NULL;
	j = 1;
	tab = av;
	while (tab[j])
	{
		check_str(tab[j]);
		if (!pile_a)
		{
			pile_a = create_elem(ft_atol(tab[j]));
			tmp = pile_a;
		}
		else
		{
			tmp->next = create_elem(ft_atol(tab[j]));
			tmp = tmp->next;
		}
		j++;
	}
	return (pile_a);
}
void	print_list(t_pile *pile_a)
{
	while (pile_a)
	{
		printf ("nb ==== %ld\n", pile_a->nbr);
		pile_a = pile_a->next;
	}
}
t_pile	*init(char **av)
{
	t_pile	*pile_a;
	
	pile_a = file_tab(av);
	if (pile_a)
	{
	check_sort(pile_a);
	check_doublon(pile_a);
	}
	return (pile_a);
}
int	main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile	*pile_b;

	int size;
	
	pile_a = NULL;
	pile_b = NULL;
	
	if (ac <= 1)
		return (0);
	pile_a = init(av);
	if (pile_a)
	{
		size = len_pile(pile_a);
		if (size == 2)
			pile_a = tri_2(pile_a);
		else if (size == 3)
			pile_a = tri_for3(pile_a);
		else if (size == 5)
			pile_a = tri_for5(pile_a, pile_b); 
		else
			pile_a = push_lessmedian(pile_a, pile_b, size);
	}
	return (0);
}
