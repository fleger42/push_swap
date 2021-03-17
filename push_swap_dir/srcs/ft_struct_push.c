/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:08:33 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 23:51:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push		ft_create_t_push(int ac, char **av)
{
	t_push	push;

	push.ac = ac;
	push.av = av;
	push.first_b = NULL;
	push.last_b = NULL;
	push.first_a = NULL;
	push.last_a = NULL;
	push.pb_size = 0;
	push.pa_size = 0;
	push.all_list = NULL;
	push.all_list_size = NULL;
	push.etape = 0;
	push.nbr_list = 0;
	push.sorted_tab = NULL;
	return (push);
}

t_push		*ft_malloc_t_push(int ac, char **av)
{
	t_push	*push;

	push = (t_push*)malloc(sizeof(t_push));
	*push = ft_create_t_push(ac, av);
	return (push);
}

void		ft_free_t_push(t_push *to_free)
{
	int i;

	i = -1;
	free(to_free->sorted_tab);
	while (++i < to_free->nbr_list)
		free(to_free->all_list[i]);
	free(to_free->all_list);
	free(to_free->all_list_size);
	ft_free_pile(to_free->first_a);
	ft_free_pile(to_free->first_b);
	free(to_free);
}
