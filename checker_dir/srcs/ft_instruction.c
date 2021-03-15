#include "../includes/checker.h"

void	ft_sb(t_push *push) //swap a : swap the first_a 2 elements at the top of stack a. Do nothing if there is only one or no elements).
{
	int temp;
	t_pile *pile;

	if(push->pb_size <= 1)
		return ;
	pile = push->first_b;
	temp = pile->nbr;
	pile->nbr = pile->next->nbr;
	pile->next->nbr = temp;
	push->etape++;
}

void	ft_sa(t_push *push) //swap a : swap the first_a 2 elements at the top of stack a. Do nothing if there is only one or no elements).
{
	int temp;
	t_pile *pile;

	if(push->pa_size <= 1)
		return ;
	pile = push->first_a;
	temp = pile->nbr;
	pile->nbr = pile->next->nbr;
	pile->next->nbr = temp;
	push->etape++;
}

void	ft_rrb(t_push *push) //reverse rotate b : shift down all elements of stackaby 1. The last_b elementbecomes the first_a one.
{
	t_pile *new_last_b;

	if(push->pb_size <= 1)
		return ;
	new_last_b = push->last_b->prev;
	push->last_b->prev->next = NULL;
	push->first_b->prev = push->last_b;
	push->last_b->next = push->first_b;
	push->last_b->prev = NULL;
	push->first_b = push->last_b;
	push->last_b = new_last_b;
	push->etape++;
}

void	ft_rb(t_push *push) //rotate b : shift up all elements of stackaby 1. The first_b element becomesthe last_a one.
{
	t_pile *new_first_b;

	if(push->pb_size <= 1)
		return ;
	new_first_b = push->first_b->next;
	push->first_b->next->prev = NULL;
	push->last_b->next = push->first_b;
	push->first_b->prev = push->last_b;
	push->first_b->next = NULL;
	push->last_b = push->first_b;
	push->first_b = new_first_b;
	push->etape++;
}

void	ft_rra(t_push *push) //reverse rotate a : shift down all elements of stackaby 1. The last_a elementbecomes the first_a one.
{
	t_pile *new_last_a;

	if(push->pa_size <= 1)
		return ;
	new_last_a = push->last_a->prev;
	push->last_a->prev->next = NULL;
	push->first_a->prev = push->last_a;
	push->last_a->next = push->first_a;
	push->last_a->prev = NULL;
	push->first_a = push->last_a;
	push->last_a = new_last_a;
	push->etape++;
}

void	ft_ra(t_push *push) //rotate a : shift up all elements of stackaby 1. The first_a element becomesthe last_a one.
{
	t_pile *new_first_a;

	if(push->pa_size <= 1)
		return ;
	new_first_a = push->first_a->next;
	push->first_a->next->prev = NULL;
	push->last_a->next = push->first_a;
	push->first_a->prev = push->last_a;
	push->first_a->next = NULL;
	push->last_a = push->first_a;
	push->first_a = new_first_a;
	push->etape++;
}

void	ft_push_b(t_push *push)
{
	if(push->pa_size == 0)
		return ;
	if(push->first_b == NULL || push->last_b == NULL)
		ft_pile_create_first(push, push->first_a->nbr, BETA);
	else
		ft_insert_before(push, push->first_b, ft_get_actual_pile(push->first_a->nbr), BETA);
	ft_remove_pile(push, push->first_a, ALPHA);
	push->pb_size = ft_size_pile(push->first_b);
	push->pa_size = ft_size_pile(push->first_a);
	push->etape++;
}

void	ft_push_a(t_push *push)
{
	if(push->pb_size == 0)
		return ;
	if(push->first_a == NULL || push->last_a == NULL)
		ft_pile_create_first(push, push->first_b->nbr, ALPHA);
	else
		ft_insert_before(push, push->first_a, ft_get_actual_pile(push->first_b->nbr), ALPHA);
	ft_remove_pile(push, push->first_b, BETA);
	push->pa_size = ft_size_pile(push->first_a);
	push->pb_size = ft_size_pile(push->first_b);
	push->etape++;
}
