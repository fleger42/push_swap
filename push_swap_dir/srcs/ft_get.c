/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:36:28 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:39:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_get_index(t_pile *pile)
{
	int i;

	i = 0;
	while (pile && pile->prev)
	{
		pile = pile->prev;
		i++;
	}
	return (i);
}

int			ft_get_from_end(t_push *push, int from_end, int nbr)
{
	while (nbr > push->end->nbr)
	{
		push->end = push->end->prev;
		from_end++;
	}
	return (from_end);
}

int			ft_get_from_top(t_push *push, int from_start, int nbr)
{
	while (nbr < push->start->nbr)
	{
		push->start = push->start->next;
		from_start++;
	}
	return (from_start);
}
