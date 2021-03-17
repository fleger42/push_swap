/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_pile_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:08:56 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 23:37:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_insert_after(t_pile *pile, t_pile *new)
{
	if (pile == NULL)
		return ;
	new->prev = pile;
	if (pile->next == NULL)
		new->next = NULL;
	else
	{
		new->next = pile->next;
		pile->next->prev = new;
	}
	pile->next = new;
}

void		ft_insert_before(t_push *push, t_pile *pile, t_pile *new, int ver)
{
	if (pile == NULL)
		return ;
	new->next = pile;
	if (pile->prev == NULL)
	{
		new->prev = NULL;
		if (ver == ALPHA)
			push->first_a = new;
		else
			push->first_b = new;
	}
	else
	{
		new->prev = pile->prev;
		pile->prev->next = new;
	}
	pile->prev = new;
}

void		ft_remove_pile(t_push *push, t_pile *to_supp, int ver)
{
	if (to_supp == NULL)
		return ;
	if (to_supp->prev == NULL)
	{
		if (ver == ALPHA)
			push->first_a = to_supp->next;
		else
			push->first_b = to_supp->next;
	}
	else
		to_supp->prev->next = to_supp->next;
	if (to_supp->next != NULL)
		to_supp->next->prev = to_supp->prev;
	free(to_supp);
}

t_pile		*ft_dup_pile(t_pile *pile)
{
	t_pile *new;

	new = malloc(sizeof(t_pile));
	new->nbr = pile->nbr;
	return (new);
}
