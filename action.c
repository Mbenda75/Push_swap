/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:05:25 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/19 19:15:56 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_lst *stk, int size)
{
	int tmp;
	
	tmp = stk->pile_a.tab[size];
	stk->pile_a.tab[size] = stk->pile_a.tab[size - 1];
	stk->pile_a.tab[size - 1] = tmp;
	
	while (size > 0)
	{
		printf("pile_a[%d] ==== %d\n", size, stk->pile_a.tab[size]);
		size--;
	}
}

void    rotate_a(t_lst *stk, int size)
{
    int i;
    i = 0;
    stk->pile_a.tab[i] = stk->pile_a.tab[size];
	printf("RA === %d\n", stk->pile_a.tab[i]);
}

void    push_b(t_lst *stk, int size)
{
    stk->pile_b.tab[0] = stk->pile_a.tab[size];
    printf("pb.tab === %d\n", stk->pile_b.tab[0]);
}
