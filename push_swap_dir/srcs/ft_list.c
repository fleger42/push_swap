/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:32:13 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:38:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_create_sorted_tab(t_push *push, char **av)
{
	int		*sorted_tab;
	int		i;
	int		temp;

	i = 0;
	sorted_tab = malloc(sizeof(int) * push->pa_size);
	while (i < push->pa_size)
	{
		sorted_tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	i = 0;
	while (i < push->pa_size)
	{
		if (i + 1 < push->pa_size && sorted_tab[i] > sorted_tab[i + 1])
		{
			temp = sorted_tab[i];
			sorted_tab[i] = sorted_tab[i + 1];
			sorted_tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	push->sorted_tab = sorted_tab;
}

int			*ft_create_liste(int *tab, int start, int end)
{
	int i;
	int *list;
	int j;

	j = 0;
	i = 0;
	list = malloc(sizeof(int) * (end - start));
	while (i < start)
		i++;
	while (i < end)
	{
		list[j++] = tab[i];
		i++;
	}
	return (list);
}

void		ft_create_all_list(t_push *push, int nbr_list)
{
	int	i;
	int start;
	int end;
	int q;

	if (nbr_list == 0)
		return ;
	q = (push->pa_size - (push->pa_size % 10)) / nbr_list;
	push->all_list = malloc(sizeof(int*) * nbr_list);
	push->all_list_size = malloc(sizeof(int) * nbr_list);
	push->rest = push->pa_size % 10;
	i = 0;
	start = 0;
	end = q;
	while (i < nbr_list)
	{
		if (i + 1 == nbr_list)
			end += push->rest;
		push->all_list_size[i] = end - start;
		push->all_list[i] = ft_create_liste(push->sorted_tab, start, end);
		start += q;
		end += q;
		i++;
	}
}

int			ft_is_in_list(int nbr, int *liste, int liste_size)
{
	int i;

	i = 0;
	while (i < liste_size)
	{
		if (nbr == liste[i])
			return (1);
		i++;
	}
	return (0);
}
