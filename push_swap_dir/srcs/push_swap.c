#include "../includes/push_swap.h"

int		ft_timeto_top(t_push *push, int index)
{
	if((double)push->pa_size/(double)index > 2.0) //Faster with ra
	{
		return (index);
	}
	else //Faster with rra
		return((index - push->pa_size) * -1);
}

void		ft_find_list(t_push *push)
{
	t_pile *first;
	t_pile *second;
	int		length;
	int		count;

	first = push->first_a;
	count = 0;
	push->liste_length = 0;
	//ft_print_t_pile(push->first_a, push->first_b);
	while(first)
	{
		length = 1;
		second = first;
		//printf("on %d : ", second->nbr);
		while(second && second->next && (second->nbr < second->next->nbr))
		{
			length++;
			second = second->next;
		}
		//printf("found length of %d\n", length);
		if(length > push->liste_length)
		{
			push->liste = first;
			push->liste_length = length;
			push->liste_index = count;
		}
		else if (length == push->liste_length)
		{
			//printf("You need ");
			//printf("%d ", ft_timeto_top(push, count));
			//printf("step to push %d (index = %d) on top\n", first->nbr, count);

			//printf("You need ");
			//printf("%d ", ft_timeto_top(push, push->liste_index));
			//printf("step to push %d (index = %d) on top\n", push->liste->nbr, push->liste_index);
			if(ft_timeto_top(push, push->liste_index) > ft_timeto_top(push, count))
			{
				push->liste = first;
				push->liste_length = length;
				push->liste_index = count;
			}
			//printf("chose : %d\n", push->liste->nbr);
		}
		count++;
		first = first->next;
	}
	//printf("The longest list found in pile_a start at %d\n", push->liste->nbr);
}

void	ft_pushlist_top(t_push *push)
{
	int time;

	time = ft_timeto_top(push, push->liste_index);
	if((double)push->pa_size/(double)push->liste_index > 2.0)
	{
		while(time--)
			ft_ra(push);
	}
	else
	{
		while(time--)
			ft_rra(push);
	}
}

void	ft_rearrange_b(t_push *push, int nbr)
{
	t_pile *end;
	t_pile *start;
	int from_start;
	int from_end;

	from_end = 0;
	from_start = 0;
	start = push->first_b;
	end = push->last_b;
	printf("Before\n");
	ft_print_t_pile(push->first_a, push->first_b);
	if(nbr > push->first_b->nbr)
	{
		ft_push_b(push);
	}
	else if(nbr < push->last_b->nbr)
	{
		ft_push_b(push);
		ft_rb(push);
	}
	else
	{
		while(nbr > end->nbr)
		{
			end = end->prev;
			from_end++;
		}
		while(nbr < start->nbr)
		{
			start = start->next;
			from_start++;
		}
		if(from_start < from_end)
		{
			from_end = from_start;
			while(from_start--)
				ft_rb(push);
			ft_push_b(push);
			while(from_end--)
				ft_rrb(push);;
		}
		else
		{
			from_start = from_end + 1;
			while(from_end--)
				ft_rrb(push);
			ft_push_b(push);
			while(from_start--)
				ft_rb(push);
		}
	}
	printf("After\n");
	ft_print_t_pile(push->first_a, push->first_b);
}

void	ft_pushlist_b(t_push *push)
{
	int i;
	t_pile *liste;

	liste = push->liste;
	i = 0;
	if(push->pb_size == 0)
	{
		while(i < push->liste_length)
		{
			ft_push_b(push);
			i++;
		}
	}
	else
	{
		while(i < push->liste_length)
		{
			ft_rearrange_b(push, liste->nbr);
			liste = liste->next;
			i++;
		}
	}
}

int		ft_get_biggest_index(t_pile *pile)
{
	int big;
	int big_index;
	int i;

	i = 0;
	big_index = 0;
	big = pile->nbr;
	while(pile)
	{
		if(pile->nbr > big)
		{
			big_index = i;
			big = pile->nbr;
		}
		pile = pile->next;
		i++;
	}
	return (big_index);
}

int		ft_get_tiniest_index(t_pile *pile)
{
	int little;
	int little_index;
	int i;

	i = 0;
	little_index = 0;
	little = pile->nbr;
	while(pile)
	{
		if(pile->nbr < little)
		{
			little_index = i;
			little = pile->nbr;
		}
		pile = pile->next;
		i++;
	}
	return (little_index);
}

void	ft_hardcode(t_push *push, int big_index, int little_index)
{
	if(big_index == 2 && little_index == 1)
		ft_sa(push);
	else if(big_index == 0 && little_index == 2)
	{
		ft_sa(push);
		ft_rra(push);
	}
	else if(big_index == 0 && little_index == 1)
	{
		ft_ra(push);
	}
	else if(big_index == 1 && little_index == 0)
	{
		ft_sa(push);
		ft_ra(push);
	}
	else if(big_index == 1 && little_index == 2)
	{
		ft_rra(push);
	}
}

int		ft_size_pile(t_pile *pile)
{
	t_pile *actual;

	actual = pile;
	int size;

	size = 0;
	while(actual)
	{
		size++;
		actual = actual->next;
	}
	return (size);
}

void	ft_get_little_up(t_push *push)
{
	int little_index;
	int size;

	size = ft_size_pile(push->first_a);
	little_index = ft_get_tiniest_index(push->first_a);
	while(little_index != 0)
	{
		if((double)size/(double)little_index < 2.0)
			ft_rra(push);
		else
			ft_ra(push);
		size = ft_size_pile(push->first_a);
		little_index = ft_get_tiniest_index(push->first_a);
	}
}

void	ft_big(t_push *push)
{
	ft_print_t_pile(push->first_a, push->first_b);
	while(push->pa_size != 0)
	{

		ft_find_list(push);
		ft_pushlist_top(push);
		ft_pushlist_b(push);
		push->pb_size = ft_size_pile(push->first_b);
		push->pa_size = ft_size_pile(push->first_a);
	}
	while (push->pb_size != 0)
	{
		ft_push_a(push);
		push->pb_size = ft_size_pile(push->first_b);
	}
	ft_print_t_pile(push->first_a, push->first_b);
}

int		*ft_create_liste(int *tab, int start, int end)
{
	int i;
	int *list;
	int j;

	printf("Create a list from %d to %d\n", start, end);
	j = 0;
	i = 0;
	list = malloc(sizeof(int) * (end - start));
	while(i < start)
		i++;
	while (i < end)
	{
		list[j++] = tab[i];
		i++;
	}
	return (list);
}

void	ft_create_all_list(t_push *push, int nbr_list)
{
	int	i;
	int start;
	int end;
	int q;

	q = (push->pa_size - (push->pa_size%10))/5;
	push->all_list = malloc(sizeof(int*) * nbr_list);
	push->all_list_size = malloc(sizeof(int) * nbr_list);
	push->rest = push->pa_size%10;
	i = 0;
	start = 0;
	end = q;
	while(i < nbr_list)
	{		
		push->all_list_size[i] = end - start;
		push->all_list[i] = ft_create_liste(push->sorted_tab, start, end);
		start += q;
		end += q;
		if(i + 2 == nbr_list)
		{
			end += push->rest;
		}
		i++;
	}
}

void	ft_printf_all_list(t_push *push)
{
	int i;
	int j;

	i = 0;
	while(i < push->all_list_size[push->nbr_list - 1])
	{
		j = 0;
		while(j < push->nbr_list)
		{
			if(push->all_list_size[j] > i)
				printf("[%d]  ", push->all_list[j][i]);
			else
				printf("      ");
			if(push->all_list_size[j] > i && push->all_list[j][i] < 10)
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_hundred(t_push *push)
{
	push->nbr_list = 5;
	ft_create_all_list(push, push->nbr_list);
	ft_printf_all_list(push);
}

void	ft_little(t_push *push)
{
	ft_print_t_pile(push->first_a, push->first_b);
	while(ft_sorted(push->first_a) == 0 || push->first_b != NULL)
	{
		if(ft_size_pile(push->first_a) == 2)
			ft_sa(push);
		else if(ft_size_pile(push->first_a) == 3)
		{
			ft_three(push);
			while(push->first_b != NULL)
				ft_push_a(push);
		}
		else if(ft_size_pile(push->first_a) == 5)
		{
			ft_five(push);
			while(push->first_b != NULL)
				ft_push_a(push);
		}
		else
		{
			ft_get_little_up(push);
			ft_push_b(push);
		}
		ft_print_t_pile(push->first_a, push->first_b);
	}
}

t_pile	*ft_get_tiniest(t_pile *pile)
{
	t_pile *little;
	int little_index;
	int	i;

	little = pile;
	i = -1;
	little_index = ft_get_tiniest_index(pile);
	while(++i < little_index)
		little = little->next;
	return (little);
}

t_pile	*ft_get_biggest(t_pile *pile)
{
	t_pile *biggest;
	int biggest_index;
	int	i;

	biggest = pile;
	i = -1;
	biggest_index = ft_get_biggest_index(pile);
	while(++i < biggest_index)
		biggest = biggest->next;
	return (biggest);
}

int		ft_get_index(t_pile *pile)
{
	int i;

	i = 0;
	while(pile && pile->prev)
	{
		pile = pile->prev;
		i++;
	}
	return (i);
}

void	ft_insert_ina(t_push *push)
{
	t_pile *little;
	t_pile *biggest;

	int		nbr;
	int		to_up;

	to_up = 0;
	nbr = push->first_b->nbr;
	little = ft_get_tiniest(push->first_a);
	biggest = ft_get_biggest(push->first_a);
	while(little && little->nbr < nbr && little->nbr != biggest->nbr)
	{
		if(little->next == NULL)
		{
			if(nbr > biggest->nbr)
				to_up++;
			little = push->first_a;
		}
		else
			little = little->next;
	}
	to_up += ft_get_index(little);
	if(to_up == 0 || (push->last_a->nbr == little->nbr && nbr > push->last_a->nbr))
		ft_push_a(push);
	else
	{
		while(to_up--)
			ft_ra(push);
		ft_push_a(push);
	}
	ft_print_t_pile(push->first_a, push->first_b);
}

void	ft_five(t_push *push)
{
	ft_push_b(push);
	ft_push_b(push);
	ft_print_t_pile(push->first_a, push->first_b);
	ft_three(push);
	ft_insert_ina(push);
	ft_insert_ina(push);
	ft_get_little_up(push);
}

void	ft_three(t_push *push)
{
	int big_index;
	int little_index;

	big_index = ft_get_biggest_index(push->first_a);
	little_index = ft_get_tiniest_index(push->first_a);
	ft_hardcode(push, big_index, little_index);
}

void	ft_print_int_tab(int *tab, int tab_size)
{
	int i;

	i = 0;
	while(i < tab_size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	ft_create_sorted_tab(t_push *push, char **av)
{
	int		*sorted_tab;
	int		i;
	int		temp;

	i = 0;
	sorted_tab = malloc(sizeof(int) * push->pa_size);
	while(i < push->pa_size)
	{
		sorted_tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	i = 0;
	while(i < push->pa_size)
	{
		if(i + 1 < push->pa_size && sorted_tab[i] > sorted_tab[i + 1])
		{
			temp = sorted_tab[i];
			sorted_tab[i] = sorted_tab[i + 1];
			sorted_tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	push->sorted_tab = sorted_tab;
}

int main(int ac, char **av)
{
	t_push *push;

	push = ft_malloc_t_push(ac, av);
	ft_verif(push);
	ft_pile_create_a(push, av);
	ft_print_t_pile(push->first_a, push->first_b);
	ft_create_sorted_tab(push, av);
	if(ac == 4)
		ft_three(push);
	else if (ac == 6)
		ft_five(push);
	else if (ac <= 100)
		ft_little(push);
	else if(ac <= 500)
		ft_hundred(push);
	else
		ft_big(push);
	if(ft_sorted(push->first_a) == 1 && push->first_b == NULL)
		printf("Sort of [%d] number done in %d instructions\n", ft_size_pile(push->first_a), push->etape);
	else
		printf("Error : pile a is not sorted or pile b is not empty. [%d] instructions done\n", push->etape);
}