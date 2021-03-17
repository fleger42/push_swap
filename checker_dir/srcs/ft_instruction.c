/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:58:33 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 02:03:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_rra(t_push *push)
{
	t_pile	*new_last_a;

	if (push->pa_size <= 1)
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

void	ft_ra(t_push *push)
{
	t_pile	*new_first_a;

	if (push->pa_size <= 1)
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
	if (push->pa_size == 0)
		return ;
	if (push->first_b == NULL || push->last_b == NULL)
		ft_pile_create_first(push, push->first_a->nbr, BETA);
	else
		ft_insert_before(push, push->first_b,
		ft_get_actual_pile(push->first_a->nbr), BETA);
	ft_remove_pile(push, push->first_a, ALPHA);
	push->pb_size = ft_size_pile(push->first_b);
	push->pa_size = ft_size_pile(push->first_a);
	push->etape++;
}

void	ft_push_a(t_push *push)
{
	if (push->pb_size == 0)
		return ;
	if (push->first_a == NULL || push->last_a == NULL)
		ft_pile_create_first(push, push->first_b->nbr, ALPHA);
	else
		ft_insert_before(push, push->first_a,
		ft_get_actual_pile(push->first_b->nbr), ALPHA);
	ft_remove_pile(push, push->first_b, BETA);
	push->pa_size = ft_size_pile(push->first_a);
	push->pb_size = ft_size_pile(push->first_b);
	push->etape++;
}
