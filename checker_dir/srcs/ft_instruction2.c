/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:03:21 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 02:03:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_sb(t_push *push)
{
	int		temp;
	t_pile	*pile;

	if (push->pb_size <= 1)
		return ;
	pile = push->first_b;
	temp = pile->nbr;
	pile->nbr = pile->next->nbr;
	pile->next->nbr = temp;
	push->etape++;
}

void	ft_sa(t_push *push)
{
	int		temp;
	t_pile	*pile;

	if (push->pa_size <= 1)
		return ;
	pile = push->first_a;
	temp = pile->nbr;
	pile->nbr = pile->next->nbr;
	pile->next->nbr = temp;
	push->etape++;
}

void	ft_rrb(t_push *push)
{
	t_pile	*new_last_b;

	if (push->pb_size <= 1)
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

void	ft_rb(t_push *push)
{
	t_pile	*new_first_b;

	if (push->pb_size <= 1)
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
