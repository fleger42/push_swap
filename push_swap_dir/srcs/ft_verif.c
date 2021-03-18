/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:11:45 by user42            #+#    #+#             */
/*   Updated: 2021/03/18 16:39:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_sorted(t_pile *pile)
{
	int actual;

	while (pile)
	{
		actual = pile->nbr;
		if (pile->next != NULL && actual > pile->next->nbr)
		{
			return (0);
		}
		pile = pile->next;
	}
	return (1);
}

int			ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "-") == 0)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		ft_verif_line(t_push *push, int i)
{
	int j;

	j = 0;
	while (push->av[i][j])
	{
		ft_atoli(push->av[i]);
		if (errno == ERANGE)
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_t_push(push);
			exit(1);
		}
		j++;
	}
	if (!ft_isnumber(push->av[i]))
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_t_push(push);
		exit(1);
	}
}

void		ft_check_dupe(t_push *push)
{
	int i;
	int j;
	int nbr;

	i = 1;
	while (i < push->ac)
	{
		j = 1;
		nbr = ft_atoi(push->av[i]);
		while (j < push->ac)
		{
			if (j != i && nbr == ft_atoi(push->av[j]))
			{
				ft_putstr_fd("Error\n", 2);
				ft_free_t_push(push);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void		ft_verif(t_push *push)
{
	int i;

	i = 1;
	if (push->ac < 2)
	{
		ft_free_t_push(push);
		exit(1);
	}
	while (i < push->ac)
	{
		ft_verif_line(push, i);
		if (push->av[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_t_push(push);
			exit(1);
		}
		i++;
	}
	ft_check_dupe(push);
}
