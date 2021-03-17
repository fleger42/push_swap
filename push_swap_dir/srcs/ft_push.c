/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:28:52 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:48:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_pushlist_b(t_push *push)
{
	int		i;
	t_pile	*liste;

	liste = push->liste;
	i = 0;
	if (push->pb_size == 0)
	{
		while (i < push->liste_length)
		{
			ft_push_b(push);
			i++;
		}
	}
	else
	{
		while (i < push->liste_length)
		{
			ft_rearrange_b(push, liste->nbr);
			liste = liste->next;
			i++;
		}
	}
}

void		ft_push_index_top(t_push *push, int index, int ver)
{
	int time_to_top;

	time_to_top = ft_timeto_top(push, index, ver);
	if (ver == ALPHA)
	{
		if ((double)push->pa_size / (double)index < 2.0)
			while (time_to_top--)
				ft_rra(push);
		else
			while (time_to_top--)
				ft_ra(push);
	}
	else
	{
		if ((double)push->pb_size / (double)index < 2.0)
			while (time_to_top--)
				ft_rrb(push);
		else
			while (time_to_top--)
				ft_rb(push);
	}
}

void		ft_push_index_bottom(t_push *push, int index, int ver)
{
	int time_to_top;

	time_to_top = ft_timeto_bottom(push, index, ver);
	if (ver == ALPHA)
	{
		if ((double)push->pa_size / (double)index > 2.0)
			while (time_to_top--)
				ft_ra(push);
		else
			while (time_to_top--)
				ft_rra(push);
	}
	else
	{
		if ((double)push->pb_size / (double)index > 2.0)
			while (time_to_top--)
				ft_rb(push);
		else
			while (time_to_top--)
				ft_rrb(push);
	}
}

void		ft_push_after(t_push *push, t_pile *pile)
{
	ft_push_index_bottom(push, ft_get_index(pile), BETA);
	ft_push_b(push);
}

void		ft_push_before(t_push *push, t_pile *pile)
{
	ft_push_index_top(push, ft_get_index(pile), BETA);
	ft_push_b(push);
}
