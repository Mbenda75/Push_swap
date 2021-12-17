/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:36 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 23:06:30 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **tab)
{
	int	line;

	line = 0;
	while (tab[line])
	{
		free(tab[line]);
		line++;
	}
	free(tab);
}

t_pile	*file_tab(char **av)
{
	int		j;
	char	**tab;
	t_pile	*tmp;
	t_pile	*pile_a;

	tab = ft_split(av[1], ' ');
	pile_a = NULL;
	j = 0;
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
	free_str(tab);
	return (pile_a);
}

t_pile	*init(char **av)
{
	t_pile	*pile_a;

	pile_a = file_tab(av);
	if (pile_a)
	{
		if (check_sort(pile_a) == 1)
			exit(1);
		check_doublon(pile_a);
	}
	return (pile_a);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		size;

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
	free_stack(pile_a);
	return (0);
}
