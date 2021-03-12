#include "push_swap.h"

void	ft_big(t_push *push)
{
	printf("Do big\n");
	(void)push;
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
}

void	ft_push_b(t_push *push)
{
	if(push->first_b == NULL && push->last_b == NULL)
		ft_pile_create_b(push, push->first_a->nbr);
	else
		ft_insert_before(push, push->first_b, ft_get_actual_pile(push->first_a->nbr), BETA);
	ft_remove_pile(push, push->first_a, ALPHA);
	//ft_print_t_pile(push->first_a, push->first_b);
	printf("pb\n");
}

void	ft_push_a(t_push *push)
{
	ft_insert_before(push, push->first_a, ft_get_actual_pile(push->first_b->nbr), ALPHA);
	ft_remove_pile(push, push->first_b, BETA);
	printf("pa\n");
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
	while(ft_sorted(push->first_a) == 0)
	{
		if(ft_size_pile(push->first_a) == 3)
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
}

int main(int ac, char **av)
{
	t_push *push;

	push = ft_malloc_t_push(ac, av);

	ft_verif(push);
	ft_pile_create_a(push, av);
	if(ac <= 51)
		ft_little(push);
	else
		ft_big(push);
}