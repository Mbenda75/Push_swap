/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:36:08 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/17 17:52:58 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	white_space(char c)
{
	if (c != '\f' && c != '\v' && c != '\n'
		&& c != '\r' && c != ' ' && c != '\t')
		return (1);
	else
		return (0);
}

void	check_str(char *str)
{
	int		i;
	long	stock;

	i = 0;
	while (str[i])
	{
		stock = ft_atol(str);
		if (stock > 2147483647 || stock < -2147483648)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		if (!ft_isdigit(str[i]) && !white_space(str[i]) && str[i] != '-')
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
}

void	check_doublon(t_pile *pile_a)
{
	int		stocknbr;
	t_pile	*start;
	t_pile	*elemtwo;
	t_pile	*compare;

	start = pile_a;
	elemtwo = pile_a;
	while (start)
	{
		stocknbr = start->nbr;
		compare = elemtwo->next;
		while (compare)
		{
			if (stocknbr == compare->nbr)
			{
				ft_putstr("Error\n");
				exit (1);
			}
			compare = compare->next;
		}
		start = start->next;
		elemtwo = elemtwo->next;
	}
}
