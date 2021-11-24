/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:54:18 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/24 12:45:03 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_stack
{
	int nbr;
	struct s_stack *next;
}				t_stack;



void		file_tab(t_lst *lst, char **av);
char		**ft_split(const char *str, char c);
static char	*ft_strnndup(const char *s1, int c);
static int	ft_counting(const char *str, char c);
t_stack		*create_elem(char **tab, int i);
t_lst		*init(char **tab);
# endif