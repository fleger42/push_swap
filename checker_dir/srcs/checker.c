/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:56:02 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 20:27:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	if (result > 2147483647 || result < -2147483648)
		errno = ERANGE;
	return (result);
}

int			ft_size_pile(t_pile *pile)
{
	t_pile	*actual;
	int		size;

	actual = pile;
	size = 0;
	while (actual)
	{
		size++;
		actual = actual->next;
	}
	return (size);
}

int			ft_instruction2(t_push *push, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		ft_push_a(push);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_b(push);
	else if (ft_strcmp(line, "sa") == 0)
		ft_sa(push);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(push);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_sa(push);
		ft_sb(push);
	}
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(push);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(push);
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_ra(push);
		ft_rb(push);
	}
	else
		return (0);
	return (1);
}

void		ft_instruction(t_push *push, char *line)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_instruction2(push, line) == 0)
		{
			if (ft_strcmp(line, "rra") == 0)
				ft_rra(push);
			else if (ft_strcmp(line, "rrb") == 0)
				ft_rrb(push);
			else if (ft_strcmp(line, "rrr") == 0)
			{
				ft_rrb(push);
				ft_rra(push);
			}
			else
			{
				ft_putstr_fd("Error\n", 2);
				ft_free_t_push(push);
				free(line);
				exit(1);
			}
		}
		free(line);
		line = NULL;
	}
}

int			main(int ac, char **av)
{
	t_push	*push;
	char	*line;

	line = NULL;
	push = ft_malloc_t_push(ac, av);
	ft_verif(push);
	ft_pile_create_a(push, av);
	ft_instruction(push, line);
	if (ft_sorted(push->first_a) == 1
	&& push->first_b == NULL)
	{
		printf("OK\n");
	}
	else
	{
		printf("KO\n");
	}
	ft_free_t_push(push);
}
