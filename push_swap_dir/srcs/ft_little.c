/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:33:01 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:38:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile		*ft_get_tiniest(t_pile *pile)
{
	t_pile	*little;
	int		little_index;
	int		i;

	little = pile;
	i = -1;
	little_index = ft_get_tiniest_index(pile);
	while (++i < little_index)
		little = little->next;
	return (little);
}

void		ft_get_little_up(t_push *push)
{
	int little_index;
	int size;

	size = ft_size_pile(push->first_a);
	little_index = ft_get_tiniest_index(push->first_a);
	while (little_index != 0)
	{
		if ((double)size / (double)little_index < 2.0)
			ft_rra(push);
		else
			ft_ra(push);
		size = ft_size_pile(push->first_a);
		little_index = ft_get_tiniest_index(push->first_a);
	}
}

int			ft_get_tiniest_index(t_pile *pile)
{
	int little;
	int little_index;
	int i;

	i = 0;
	little_index = 0;
	little = pile->nbr;
	while (pile)
	{
		if (pile->nbr < little)
		{
			little_index = i;
			little = pile->nbr;
		}
		pile = pile->next;
		i++;
	}
	return (little_index);
}
