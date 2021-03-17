/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:31:32 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:48:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_whotop(t_push *push, int i)
{
	int index_top;
	int index_bottom;

	index_top = ft_scan_afrom_top(push, push->all_list[i],
	push->all_list_size[i]);
	index_bottom = ft_scan_afrom_bottom(push, push->all_list[i],
	push->all_list_size[i]);
	if (ft_timeto_top(push, index_bottom, ALPHA)
	< ft_timeto_top(push, index_top, ALPHA))
		ft_push_index_top(push, index_bottom, ALPHA);
	else
		ft_push_index_top(push, index_top, ALPHA);
}

int			ft_scan_afrom_top(t_push *push, int *liste, int liste_size)
{
	int		i;
	t_pile	*pile;

	pile = push->first_a;
	i = 0;
	while (pile)
	{
		if (ft_is_in_list(pile->nbr, liste, liste_size))
			return (i);
		pile = pile->next;
		i++;
	}
	return (0);
}

int			ft_scan_afrom_bottom(t_push *push, int *liste, int liste_size)
{
	int		i;
	t_pile	*pile;

	pile = push->last_a;
	i = 0;
	while (pile)
	{
		if (ft_is_in_list(pile->nbr, liste, liste_size))
		{
			return (push->pa_size - (i + 1));
		}
		pile = pile->prev;
		i++;
	}
	return (0);
}
