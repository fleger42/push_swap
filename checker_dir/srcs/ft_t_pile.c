#include "../includes/checker.h"

t_pile		*ft_get_actual_pile(int nbr)
{
	t_pile *pile;

	pile = malloc(sizeof(t_pile));
	pile->nbr = nbr;
	return (pile);
}

void		ft_pile_create_first(t_push	*push, int nbr, int ver)
{
	t_pile		*elem;

	elem = ft_get_actual_pile(nbr);
	elem->next = NULL;
	elem->prev = NULL;
	if(ver == ALPHA)
	{
		push->last_a = elem;
		push->first_a = elem;
	}
	else
	{
		push->last_b = elem;
		push->first_b = elem;
	}
	push->pb_size = ft_size_pile(push->first_b);
}

void		ft_pile_create_a(t_push	*push, char **av)
{
	t_pile		*elem2;
	t_pile		*elem1;
	int			i;

	i = 1;
	elem2 = NULL;
	elem1 = NULL;
	while (av[i])
	{
		elem1 = ft_get_actual_pile(ft_atoi(av[i]));
		elem1->prev = elem2;
		if (elem2)
			elem2->next = elem1;
		elem2 = elem1;
		i++;
	}
	if (elem1)
		elem1->next = NULL;
	push->last_a = elem1;
	if (elem1)
	{
		while (elem1 && elem1->prev)
			elem1 = elem1->prev;
	}
	push->first_a = elem1;
	push->pa_size = ft_size_pile(push->first_a);
}

void		ft_free_pile(t_pile *pile)
{
	t_pile *temp;

	while (pile)
	{
		temp = pile->next;
		free(pile);
		pile = temp;
	}
}