/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:11:40 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:37:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_big(t_push *push)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	ft_scale(push);
	ft_create_all_list(push, push->nbr_list);
	while (push->pa_size != 0)
	{
		ft_whotop(push, i);
		ft_insert_inb(push);
		push->pa_size = ft_size_pile(push->first_a);
		j++;
		if (j == push->all_list_size[0])
		{
			if (i + 1 < push->nbr_list)
				i++;
			j = 0;
		}
	}
	ft_get_big_up(push);
	while (push->first_b)
		ft_push_a(push);
}

void		ft_little(t_push *push)
{
	while (ft_sorted(push->first_a) == 0 || push->first_b != NULL)
	{
		if (ft_size_pile(push->first_a) == 2)
			ft_sa(push);
		else if (ft_size_pile(push->first_a) == 3)
		{
			ft_three(push);
			while (push->first_b != NULL)
				ft_push_a(push);
		}
		else if (ft_size_pile(push->first_a) == 5)
		{
			ft_five(push);
			while (push->first_b != NULL)
				ft_push_a(push);
		}
		else
		{
			ft_get_little_up(push);
			ft_push_b(push);
		}
	}
}

void		ft_five(t_push *push)
{
	ft_push_b(push);
	ft_push_b(push);
	ft_three(push);
	ft_insert_ina(push);
	ft_insert_ina(push);
	ft_get_little_up(push);
}

void		ft_three(t_push *push)
{
	int big_index;
	int little_index;

	big_index = ft_get_biggest_index(push->first_a);
	little_index = ft_get_tiniest_index(push->first_a);
	ft_hardcode(push, big_index, little_index);
}

int			main(int ac, char **av)
{
	t_push	*push;

	push = ft_malloc_t_push(ac, av);
	ft_pile_create_a(push, av);
	ft_verif(push);
	if (push->pa_size == 1)
		;
	else if (push->pa_size == 2)
	{
		if (ft_sorted(push->first_a) == 0)
			ft_sa(push);
	}
	else if (ac == 4)
		ft_three(push);
	else if (ac == 6)
		ft_five(push);
	else if (ac <= 20)
		ft_little(push);
	else
	{
		ft_create_sorted_tab(push, av);
		ft_big(push);
	}
	ft_free_t_push(push);
}
