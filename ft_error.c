/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:36:08 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/01 16:11:05 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

void    check_str(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != '\f' && str[i] != '\t' && str[i] != '\v'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != ' ')
        {
            ft_putstr("Error\n");
            exit(1);
        }
        i++;
    }
}

void    check_doublon(t_pile *pile_a)
{
    t_pile *start;
    t_pile *elemtwo;
    t_pile *compare;
    
    int stocknb;
    start = pile_a;
    elemtwo = pile_a;
    while(start)
    {
        stocknb = start->nbr;
        compare = elemtwo->next;
        while (compare)
        {
            if (stocknb == compare->nbr)
            {
                ft_putstr("Error\n");
                exit (1);
            }
            compare = compare->next;
        }
       start = start->next;;
       elemtwo = elemtwo->next;
    }
}