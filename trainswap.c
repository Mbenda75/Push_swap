/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:16 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/24 11:39:18 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>


int size_stack(t_lst *stk, int ac)
{
	int size_a;

	size_a = ac - 1;
	
	return(size_a);
}

void	file_stack(t_lst *stk, char **av, int size_a)
{
	stk->pile_a.tab = malloc(size_a);
	stk->pile_b.tab = malloc(size_a);
	while (size_a > 0)
	{
		stk->pile_a.tab[size_a] = atoi(av[size_a]);
		printf("pile_a[%d] ==== %d\n", size_a,stk->pile_a.tab[size_a]);
		size_a--;	
	}
	stk->pile_a.tab[size_a] = '\0';
}


int main(int ac, char **av)
{
	t_lst stk;
	 int size;
	size = size_stack(&stk, ac);
	file_stack(&stk, av, size);
	printf("size == %d\n", size);
	swap_a(&stk, size);
	push_b(&stk, size);
	rotate_a(&stk, size);
	return (0);
}