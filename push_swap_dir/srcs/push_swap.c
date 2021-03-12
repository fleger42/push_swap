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

void	ft_big(t_push *push)
{
	ft_print_t_pile(push->first_a, push->first_b);
	push->pb_size = ft_size_pile(push->first_b);
	push->pa_size = ft_size_pile(push->first_a);
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
		ft_print_t_pile(push->first_a, push->first_b);
	}
	ft_print_t_pile(push->first_a, push->first_b);
	if(ft_sorted(push->first_a) == 0 || push->first_b == NULL)
		printf("Sorted\n");
	else
		printf("Error: pile a not sorted or pile b not empty\n");
	printf("Sort of [%d] number done in %d instructions\n", ft_size_pile(push->first_a), push->etape);
}

int		ft_get_biggest(t_pile *pile)
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

int		ft_get_tiniest(t_pile *pile)
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

void	ft_sa(t_push *push) //swap a : swap the first_a 2 elements at the top of stack a. Do nothing if there is only one or no elements).
{
	int temp;
	t_pile *pile;

	pile = push->first_a;
	temp = pile->nbr;
	pile->nbr = pile->next->nbr;
	pile->next->nbr = temp;
	printf("sa\n");
	push->etape++;
}

void	ft_rrb(t_push *push) //reverse rotate b : shift down all elements of stackaby 1. The last_b elementbecomes the first_a one.
{
	t_pile *new_last_b;

	new_last_b = push->last_b->prev;
	push->last_b->prev->next = NULL;
	push->first_b->prev = push->last_b;
	push->last_b->next = push->first_b;
	push->last_b->prev = NULL;
	push->first_b = push->last_b;
	push->last_b = new_last_b;
	printf("rrb\n");
	push->etape++;
}

void	ft_rb(t_push *push) //rotate b : shift up all elements of stackaby 1. The first_b element becomesthe last_a one.
{
	t_pile *new_first_b;

	new_first_b = push->first_b->next;
	push->first_b->next->prev = NULL;
	push->last_b->next = push->first_b;
	push->first_b->prev = push->last_b;
	push->first_b->next = NULL;
	push->last_b = push->first_b;
	push->first_b = new_first_b;
	printf("rb\n");
	push->etape++;
}

void	ft_rra(t_push *push) //reverse rotate a : shift down all elements of stackaby 1. The last_a elementbecomes the first_a one.
{
	t_pile *new_last_a;

	new_last_a = push->last_a->prev;
	push->last_a->prev->next = NULL;
	push->first_a->prev = push->last_a;
	push->last_a->next = push->first_a;
	push->last_a->prev = NULL;
	push->first_a = push->last_a;
	push->last_a = new_last_a;
	printf("rra\n");
	push->etape++;
}

void	ft_ra(t_push *push) //rotate a : shift up all elements of stackaby 1. The first_a element becomesthe last_a one.
{
	t_pile *new_first_a;

	new_first_a = push->first_a->next;
	push->first_a->next->prev = NULL;
	push->last_a->next = push->first_a;
	push->first_a->prev = push->last_a;
	push->first_a->next = NULL;
	push->last_a = push->first_a;
	push->first_a = new_first_a;
	printf("ra\n");
	push->etape++;
}

void	ft_push_b(t_push *push)
{
	if(push->first_b == NULL || push->last_b == NULL)
		ft_pile_create_first(push, push->first_a->nbr, BETA);
	else
		ft_insert_before(push, push->first_b, ft_get_actual_pile(push->first_a->nbr), BETA);
	ft_remove_pile(push, push->first_a, ALPHA);
	printf("pb\n");
	push->etape++;
}

void	ft_push_a(t_push *push)
{
	if(push->first_a == NULL || push->last_a == NULL)
	{
		ft_pile_create_first(push, push->first_b->nbr, ALPHA);
	}
	else
		ft_insert_before(push, push->first_a, ft_get_actual_pile(push->first_b->nbr), ALPHA);
	ft_remove_pile(push, push->first_b, BETA);
	printf("pa\n");
	push->etape++;
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

void	ft_three(t_push *push)
{
	int big_index;
	int little_index;

	big_index = ft_get_biggest(push->first_a);
	little_index = ft_get_tiniest(push->first_a);
	//printf("Biggest number index is %d\nTiniest number index is %d\n", big_index, little_index);
	//printf("First_a nbr = %d\nLast_a nbr = %d\n", push->first_a->nbr, push->last_a->nbr);

	ft_hardcode(push, big_index, little_index);
}

int		ft_size_pile(t_pile *pile)
{
	int size;

	size = 0;
	while(pile)
	{
		size++;
		pile = pile->next;
	}
	return (size);
}

void	ft_get_little_up(t_push *push)
{
	int little_index;
	int size;

	size = ft_size_pile(push->first_a);
	little_index = ft_get_tiniest(push->first_a);
	while(little_index != 0)
	{
		if((double)size/(double)little_index < 2.0)
			ft_rra(push);
		else
			ft_ra(push);
		size = ft_size_pile(push->first_a);
		little_index = ft_get_tiniest(push->first_a);
	}
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
			{
				ft_push_a(push);
			}
		}
		else
		{
			ft_get_little_up(push);
			ft_push_b(push);
		}
		ft_print_t_pile(push->first_a, push->first_b);
	}
	printf("Sort of [%d] number done in %d instructions\n", ft_size_pile(push->first_a), push->etape);
}

int main(int ac, char **av)
{
	t_push *push;

	push = ft_malloc_t_push(ac, av);

	ft_verif(push);
	ft_pile_create_a(push, av);
	
	if(ac <= 0)
		ft_little(push);
	else
		ft_big(push);
}