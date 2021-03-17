/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:32:48 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:49:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile		*ft_get_biggest(t_pile *pile)
{
	t_pile	*biggest;
	int		biggest_index;
	int		i;

	biggest = pile;
	i = -1;
	biggest_index = ft_get_biggest_index(pile);
	while (++i < biggest_index)
		biggest = biggest->next;
	return (biggest);
}

void		ft_get_big_up(t_push *push)
{
	int big_index;
	int size;

	size = ft_size_pile(push->first_b);
	big_index = ft_get_biggest_index(push->first_b);
	while (big_index != 0)
	{
		if ((double)size / (double)big_index < 2.0)
			ft_rrb(push);
		else
			ft_rb(push);
		size = ft_size_pile(push->first_b);
		big_index = ft_get_biggest_index(push->first_b);
	}
}

int			ft_get_biggest_index(t_pile *pile)
{
	int big;
	int big_index;
	int i;

	i = 0;
	big_index = 0;
	big = pile->nbr;
	while (pile)
	{
		if (pile->nbr > big)
		{
			big_index = i;
			big = pile->nbr;
		}
		pile = pile->next;
		i++;
	}
	return (big_index);
}
