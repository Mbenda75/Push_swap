/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:54:18 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/02 14:24:12 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_pile
{
	int nbr;
	struct s_pile *next;
}				t_pile;


t_pile		*file_tab(char **av);
char		**ft_split(const char *str, char c);
static char	*ft_strnndup(const char *s1, int c);
static int	ft_counting(const char *str, char c);
t_pile		*create_elem(int nbr);
t_pile		*init(char **tab);
void		print_list(t_pile *pile_a);
t_pile		*swap_a(t_pile *pile_a, int i);
int			len_pile(t_pile *pile_a);
int			ft_isdigit(char c);
void    	check_doublon(t_pile *pile_a);
void		ft_putstr(char *s);
t_pile		*rotate_a(t_pile *premier);
void		push_b(t_pile *pile_a, t_pile *pile_b);
t_pile		*rrotate_a(t_pile *pile_a);
void    	check_str(char *str);
t_pile  	*tri_three(t_pile *pile_a);
# endif