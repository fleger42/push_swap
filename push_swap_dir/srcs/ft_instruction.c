/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:08:37 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:47:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rb(t_push *push)
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

void	ft_rra(t_push *push)
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

void	ft_ra(t_push *push)
{
	t_pile	*new_first_a;

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
	if (push->first_b == NULL || push->last_b == NULL)
		ft_pile_create_first(push, push->first_a->nbr, BETA);
	else
		ft_insert_before(push, push->first_b,
		ft_get_actual_pile(push->first_a->nbr), BETA);
	ft_remove_pile(push, push->first_a, ALPHA);
	push->pb_size = ft_size_pile(push->first_b);
	printf("pb\n");
	push->etape++;
}

void	ft_push_a(t_push *push)
{
	if (push->first_a == NULL || push->last_a == NULL)
	{
		ft_pile_create_first(push, push->first_b->nbr, ALPHA);
	}
	else
		ft_insert_before(push, push->first_a,
		ft_get_actual_pile(push->first_b->nbr), ALPHA);
	ft_remove_pile(push, push->first_b, BETA);
	push->pa_size = ft_size_pile(push->first_a);
	printf("pa\n");
	push->etape++;
}
