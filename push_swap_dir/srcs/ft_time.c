/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:30:09 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 01:48:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_timeto_top(t_push *push, int index, int ver)
{
	if (ver == ALPHA)
	{
		if ((double)push->pa_size / (double)index > 2.0)
		{
			return (index);
		}
		else
			return ((index - push->pa_size) * -1);
	}
	else
	{
		if ((double)push->pb_size / (double)index > 2.0)
		{
			return (index);
		}
		else
			return ((index - push->pb_size) * -1);
	}
}

int			ft_timeto_bottom(t_push *push, int index, int ver)
{
	if (ver == ALPHA)
	{
		if ((double)push->pa_size / (double)index > 2.0)
		{
			return (index + 1);
		}
		else
			return (((index + 1) - push->pa_size) * -1);
	}
	else
	{
		if ((double)push->pb_size / (double)index > 2.0)
		{
			return (index + 1);
		}
		else
			return (((index + 1) - push->pb_size) * -1);
	}
}
