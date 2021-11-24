#include <stdlib.h>
#include <stdio.h>

typedef struct	s_pile
{
	//t_list	*pile_a;
	//t_list	*pile_b;
	struct s_pile	*next;
	void			*data;
}				t_pile;

t_pile *ft_create_elem(void *data)
{
    t_pile *lst;

    lst = malloc(sizeof(*lst));
    lst->data = data;
    lst->next = NULL;
 
    return (lst);
}

void	ft_pile_push_front(t_pile *begin, void *data)
{
	t_pile	*push;

	if (begin)
	{
		push = ft_create_elem(data);
		push->next = begin;
		begin = push;
	}

}

t_pile  *ft_last_pile(t_pile *begin)
{
    while (begin->next)
        begin = begin->next;
    return (begin);
}

int		main(int ac, char **av)
{
	t_pile	elem1, elem2, elem3, *begin;


	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = 0;


	elem1.data = av[1];
	elem2.data = av[2];
	elem3.data = av[3];
	ft_pile_push_front(begin, av[1]);
	while (begin != NULL)
	{
		printf("%s\n", begin->data);
		begin = begin->next;	
	}
	
}
