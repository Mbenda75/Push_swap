/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:05:25 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/02 13:54:51 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    ft_swap(int *a, int *b)
{
        int c;

        c = *a;
        *a = *b;
        *b = c;
}

t_pile	*swap_a(t_pile *pile_a, int i)
{
	if (pile_a->nbr && pile_a->next->nbr)
	{
		ft_swap(&(pile_a->nbr), &(pile_a->next->nbr));
	}
	if (i == 0)
		ft_putstr("sa\n");
	return(pile_a);
}

void	push_b(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a)
	{
		//pile_b->nbr = create_elem(pile_a->nbr);
	}

	print_list(pile_b);
}

t_pile	*rotate_a(t_pile *pile_a)
{
	t_pile *uno;
	t_pile *dos;
	
	uno = pile_a;
	dos = pile_a;	
	while (dos->next->next)
	{
		dos = dos->next;
	}
	uno->next = NULL;
	dos->next->next = pile_a;
	ft_putstr("ra\n");
	return(dos);
}
 
t_pile	*rrotate_a(t_pile *pile_a)
{
	t_pile *dernier;
	t_pile *avantder;
	

	avantder = pile_a;
	dernier = pile_a;
	while (dernier->next)
	{
		dernier = dernier->next;
	}
	while (avantder->next->next)
	{
		avantder = avantder->next;
	}
	dernier->next = pile_a;
	avantder->next = NULL;
	ft_putstr("rra\n");
	return (dernier);
}
 