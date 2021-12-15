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
t_pile *parition(t_pile *first, t_pile *last)
{
	//Get first elem of given linked list
	t_pile *pivot = first;
	t_pile *front = first;
	int temp = 0;
	while (front != NULL && front != last)
	{
        printf(" avant if front nbr == %d\n", front->nbr);
        printf("avant if last nbr == %d\n",last->nbr);
		if (front->nbr < last->nbr)
		{
            printf("ici\n");
			pivot = first;
			//Swap elem value
			temp = first->nbr;
			first->nbr = front->nbr;
			front->nbr = temp;
	    	//Visit to next elem
			first = first->next;
		}
		//Visit to next elem
		front = front->next;
	}
	//Change last elem value to current elem
	temp = first->nbr;
	first->nbr = last->nbr;
	last->nbr = temp;
/*     first  = rrotate_a(first);
    first = swap_a(first);
    first = rotate_a(first); */
	return pivot;
}
void	print_list(t_pile *pile_a)
{
	while (pile_a)
	{
		printf ("nb ==== %d\n", pile_a->nbr);
		pile_a = pile_a->next;
	}
}

void quick_sort(t_pile *first, t_pile *last)
{
	if (first == last)
	{
		return;
	}
	t_pile *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
	{
        printf("1\n");
        print_list(pivot);
		quick_sort(pivot->next, last);
	}
	if (pivot != NULL && first != pivot)
	{
        printf("2\n");
		quick_sort(first, pivot);
	}
}

void	print_list(t_pile *pile_a)
{
	while (pile_a)
	{
		printf ("nb ==== %ld\n", pile_a->nbr);
		pile_a = pile_a->next;
	}
}
/* t_pile    *push_lessmedian(t_pile *pile_a, t_pile *pile_b, int size, int *tab)
{
    int median;
    t_pile  *tmp;

    tmp = pile_a;
    median = size / 2;

    while (size)
    {
        if (tmp->nbr < tab[median])
        {
            pile_b = push_b(tmp, pile_b);
            tmp = supprimer_nbrhead(tmp);
        }
        else if (tmp->nbr >= tab[median])
            tmp = rotate_a(tmp);
        size--;
    }
    size = len_pile(tmp);
    median = size / 2;
    tab = tab_int(tmp, size);
	tab = value_sort(tab, size);
    while (size)
    {
        if (tmp->nbr < tab[median])
        {
            pile_b = push_b(tmp, pile_b);
            tmp = supprimer_nbrhead(tmp);
        }
        else if (tmp->nbr >= tab[median])
            tmp = rotate_a(tmp);
        size--;
    }
   
    int len = len_pile(tmp);
    int med = len / 2 ;
    tab = tab_int(tmp, len);
	tab = value_sort(tab, len);
    while (len)
    {
        if (tmp->nbr >= tab[med])
        {
            tmp = rotate_a(tmp);
        }
        else if (tmp->nbr < tab[med])
        {
            pile_b = push_b(tmp, pile_b);
            tmp = supprimer_nbrhead(tmp);
        }
        len--;
    }
    if (tmp->nbr > tmp->next->nbr)
        tmp = swap_a(tmp);
    size = len_pile(pile_b);
    while (size)
    {
        pile_b = max_totop(pile_b);
        tmp = push_a(tmp , pile_b);
        pile_b = supprimer_nbrhead(pile_b);
        size--;
    }
    printf("/*---------------------PILE_B----------------/\n");
    return (tmp);
}
*/
/*     while(pile_b)
    {
        size = len_pile(pile_b);
        tmp = pile_b;
        med = get_median(tmp, tab, size);
        while (size)
        {
            if (tmp->nbr >= med)
            {
                pile_a = push_a(pile_a, tmp);
                tmp = tmp->next;
            }
            else
                tmp = rrotate_b(tmp);
            size--; 
        }
        pile_b = tmp;
    }  */
