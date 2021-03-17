/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:47:51 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:49:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pushlist_top(t_push *push)
{
	int time;

	time = ft_timeto_top(push, push->liste_index, ALPHA);
	if ((double)push->pa_size / (double)push->liste_index > 2.0)
	{
		while (time--)
			ft_ra(push);
	}
	else
	{
		while (time--)
			ft_rra(push);
	}
}

void	ft_sa(t_push *push)
{
	int		temp;
	t_pile	*pile;

	pile = push->first_a;
	temp = pile->nbr;
	pile->nbr = pile->next->nbr;
	pile->next->nbr = temp;
	printf("sa\n");
	push->etape++;
}

void	ft_rrb(t_push *push)
{
	t_pile	*new_last_b;

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
