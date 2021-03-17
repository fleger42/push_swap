/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:27:59 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:42:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_endinsert_ina(t_push *push, int to_up, int nbr, t_pile *little)
{
	if (to_up == 0 || (push->last_a->nbr == little->nbr &&
	nbr > push->last_a->nbr))
		ft_push_a(push);
	else
	{
		while (to_up--)
			ft_ra(push);
		ft_push_a(push);
	}
}

void		ft_insert_ina(t_push *push)
{
	t_pile	*little;
	t_pile	*biggest;
	int		nbr;
	int		to_up;

	to_up = 0;
	nbr = push->first_b->nbr;
	little = ft_get_tiniest(push->first_a);
	biggest = ft_get_biggest(push->first_a);
	while (little && little->nbr < nbr && little->nbr != biggest->nbr)
	{
		if (little->next == NULL)
		{
			if (nbr > biggest->nbr)
				to_up++;
			little = push->first_a;
		}
		else
			little = little->next;
	}
	to_up += ft_get_index(little);
	ft_endinsert_ina(push, to_up, nbr, little);
}

int			ft_startinsert_inb(t_push *push, int nbr, t_pile *little,
t_pile *pile)
{
	if (nbr > pile->nbr)
	{
		ft_push_before(push, pile);
		return (1);
	}
	if (nbr < little->nbr)
	{
		ft_push_after(push, little);
		return (1);
	}
	return (0);
}

void		ft_insert_inb(t_push *push)
{
	t_pile	*little;
	t_pile	*pile;
	int		nbr;

	if (push->pb_size == 0 || push->pb_size == 1)
	{
		ft_push_b(push);
		return ;
	}
	nbr = push->first_a->nbr;
	little = ft_get_tiniest(push->first_b);
	pile = ft_get_biggest(push->first_b);
	if (ft_startinsert_inb(push, nbr, little, pile))
		return ;
	while (pile && nbr < pile->nbr && pile->nbr != little->nbr)
	{
		if (pile->next == NULL)
			pile = push->first_b;
		else
			pile = pile->next;
	}
	ft_push_before(push, pile);
}
