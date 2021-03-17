/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:01:11 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 02:02:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

long int	ft_atoli(const char *nptr)
{
	int				i;
	long int		result;
	int				signe;

	signe = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i++] - 48);
	}
	result = result * signe;
	if (result > 2147483647 || result < (long int)-2147483648)
		errno = ERANGE;
	return (result);
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

void		ft_verif(t_push *push)
{
	int i;

	i = 1;
	if (push->ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_t_push(push);
		exit(1);
	}
	while (i < push->ac)
	{
		ft_verif_line(push, i);
		i++;
	}
}
