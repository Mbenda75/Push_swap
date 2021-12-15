/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:54:18 by benmoham          #+#    #+#             */
/*   Updated: 2021/12/15 17:02:45 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef	struct	s_pile
{
	long nbr;
	struct s_pile *next;
}				t_pile;

/*------------------ACTIONS-----------------------*/
t_pile		*rotate_a(t_pile *premier);
t_pile		*rrotate_a(t_pile *pile_a);
t_pile		*swap_a(t_pile *pile_a);
t_pile		*push_b(t_pile *pile_a, t_pile *pile_b);
t_pile		*push_a(t_pile *pile_a, t_pile *pile_b);
t_pile		*rrotate_b(t_pile *pile_b);

/*-----------------PARSING-----------------------*/
t_pile		*file_tab(char **av);
t_pile		*create_elem(int nbr);
t_pile		*init(char **av);
int			ft_isdigit(char c);
void    	check_doublon(t_pile *pile_a);
void    	check_str(char *str);
void		check_max_min(t_pile *pile_a);

/*-----------------TRI---------------------------*/
t_pile		*tri_2(t_pile *pile_a);
t_pile		*tri_for3(t_pile *pile_a);
t_pile  	*tri_for5(t_pile *pile_a, t_pile *pile_b);
t_pile  	*min_totop(t_pile *pile_a);
t_pile  	*max_totop(t_pile *pile_a);
t_pile  	*lastnbr(t_pile *pile_a);
t_pile   	*push_lessmedian(t_pile *pile_a, t_pile *pile_b, int size);
t_pile  	*last_sort(t_pile *pile_a, t_pile *pile_b);
t_pile  	*max_sort_top(t_pile *pile_a, t_pile *pile_b);
int			search_posmax(t_pile  *pile_a);
int			search_posmin(t_pile  *pile_a);
int    		check_sort(t_pile *pile_a);
int			*value_sort(int *tab, int len);

/*----------------UTILS-------------------------*/
void		ft_putstr(char *s);
void		ft_swap(long *a, long *b);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		print_list(t_pile *pile_a);
int			len_pile(t_pile *pile_a);
char		**ft_split(const char *str, char c);
int    		*tab_int(t_pile *pile_a, int size);
t_pile		*ft_list_push_back(t_pile *pile_a, int nbr);
t_pile 		*supprimer_nbrhead(t_pile *pile_a); 
t_pile		*ajouter_nbrhead(t_pile	*liste, int valeur);
long		ft_atol(const char *str);

# endif