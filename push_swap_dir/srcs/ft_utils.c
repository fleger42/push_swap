/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:37:22 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:37:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_rearrange_b2(t_push *push, int nbr, int from_start, int from_end)
{
	from_start = ft_get_from_top(push, from_end, nbr);
	from_end = ft_get_from_end(push, from_end, nbr);
	if (from_start < from_end)
	{
		from_end = from_start;
		while (from_start--)
			ft_rb(push);
		ft_push_b(push);
		while (from_end--)
			ft_rrb(push);
	}
	else
	{
		from_start = from_end + 1;
		while (from_end--)
			ft_rrb(push);
		ft_push_b(push);
		while (from_start--)
			ft_rb(push);
	}
}

void		ft_rearrange_b(t_push *push, int nbr)
{
	int		from_start;
	int		from_end;

	from_end = 0;
	from_start = 0;
	push->start = push->first_b;
	push->end = push->last_b;
	if (nbr > push->first_b->nbr)
		ft_push_b(push);
	else if (nbr < push->last_b->nbr)
	{
		ft_push_b(push);
		ft_rb(push);
	}
	else
		ft_rearrange_b2(push, nbr, from_start, from_end);
}

void		ft_hardcode(t_push *push, int big_index, int little_index)
{
	if (big_index == 2 && little_index == 1)
		ft_sa(push);
	else if (big_index == 0 && little_index == 2)
	{
		ft_sa(push);
		ft_rra(push);
	}
	else if (big_index == 0 && little_index == 1)
	{
		ft_ra(push);
	}
	else if (big_index == 1 && little_index == 0)
	{
		ft_sa(push);
		ft_ra(push);
	}
	else if (big_index == 1 && little_index == 2)
	{
		ft_rra(push);
	}
}

int			ft_size_pile(t_pile *pile)
{
	t_pile	*actual;
	int		size;

	actual = pile;
	size = 0;
	while (actual)
	{
		size++;
		actual = actual->next;
	}
	return (size);
}

void		ft_scale(t_push *push)
{
	if (push->pa_size < 100)
		push->nbr_list = 4;
	if (push->pa_size >= 100 && push->pa_size < 500)
		push->nbr_list = 6;
	if (push->pa_size >= 500 && push->pa_size < 1000)
		push->nbr_list = 12;
	if (push->pa_size >= 1000)
		push->nbr_list = 18;
}
