/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:22 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/18 18:27:11 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
void    ft_swap(int *a, int *b)
{
        int c;

        c = *a;
        *a = *b;
        *b = c;
}
typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list *ft_create_elem(void *data)
{
    t_list *lst;

    lst = malloc(sizeof(*lst));
    
    lst->data = data;
    lst->next = NULL;
 
    return (lst);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);

	}
	else
		*begin_list = ft_create_elem(data);
}

int		main(void)
{
	t_list	elem1, elem2, elem3, *begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = 0;

	elem1.data = "toto";
	elem2.data = "tata";
	elem3.data = "tutu";

	ft_list_push_back(&begin, "tasoeur");

	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;	
	}
}