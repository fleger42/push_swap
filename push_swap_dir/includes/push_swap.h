/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:06:02 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 02:21:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../../libft/libft.h"
# include "errno.h"
# define ALPHA 1
# define BETA 0
# define RRA 3
# define RA 2

typedef struct		s_push
{
	int				ac;
	char			**av;
	int				*sorted_tab;
	int				etape;
	struct s_pile	*first_a;
	int				pa_size;
	struct s_pile	*last_a;
	struct s_pile	*first_b;
	int				pb_size;
	struct s_pile	*last_b;
	struct s_pile	*liste;
	int				liste_index;
	int				liste_length;
	int				nbr_list;
	int				rest;
	int				**all_list;
	int				*all_list_size;
	int				next_move;
	struct s_pile	*end;
	struct s_pile	*start;
}					t_push;
typedef struct		s_pile
{
	int				nbr;
	struct s_pile	*prev;
	struct s_pile	*next;
}					t_pile;
void				ft_big(t_push *push);
void				ft_little(t_push *push);
void				ft_five(t_push *push);
void				ft_three(t_push *push);
int					main(int ac, char **av);
int					ft_sorted(t_pile *pile);
long int			ft_atoli(const char *nptr);
int					ft_isnumber(char *str);
void				ft_verif_line(t_push *push, int i);
void				ft_verif(t_push *push);
void				ft_rearrange_b2(t_push *push, int nbr, int from_start,
int from_end);
void				ft_rearrange_b(t_push *push, int nbr);
void				ft_hardcode(t_push *push, int big_index, int little_index);
int					ft_size_pile(t_pile *pile);
void				ft_scale(t_push *push);
int					ft_timeto_top(t_push *push, int index, int ver);
int					ft_timeto_bottom(t_push *push, int index, int ver);
t_pile				*ft_get_actual_pile(int nbr);
void				ft_pile_create_first(t_push *push, int nbr, int ver);
void				ft_pile_create_a(t_push *push, char **av);
void				ft_free_pile(t_pile *pile);
void				ft_insert_after(t_pile *pile, t_pile *new);
void				ft_insert_before(t_push *push, t_pile *pile, t_pile *new,
int ver);
void				ft_remove_pile(t_push *push, t_pile *to_supp, int ver);
t_pile				*ft_dup_pile(t_pile *pile);
t_push				ft_create_t_push(int ac, char **av);
t_push				*ft_malloc_t_push(int ac, char **av);
void				ft_free_t_push(t_push *to_free);
void				ft_whotop(t_push *push, int i);
int					ft_scan_afrom_top(t_push *push, int *liste,
int liste_size);
int					ft_scan_afrom_bottom(t_push *push, int *liste,
int liste_size);
void				ft_pushlist_top(t_push *push);
void				ft_pushlist_b(t_push *push);
void				ft_push_index_top(t_push *push, int index, int ver);
void				ft_push_index_bottom(t_push *push, int index, int ver);
void				ft_push_after(t_push *push, t_pile *pile);
void				ft_push_before(t_push *push, t_pile *pile);
t_pile				*ft_get_tiniest(t_pile *pile);
void				ft_get_little_up(t_push *push);
int					ft_get_tiniest_index(t_pile *pile);
void				ft_create_sorted_tab(t_push *push, char **av);
int					*ft_create_liste(int *tab, int start, int end);
void				ft_create_all_list(t_push *push, int nbr_list);
int					ft_is_in_list(int nbr, int *liste, int liste_size);
void				ft_sa(t_push *push);
void				ft_rrb(t_push *push);
void				ft_rb(t_push *push);
void				ft_rra(t_push *push);
void				ft_ra(t_push *push);
void				ft_push_b(t_push *push);
void				ft_push_a(t_push *push);
void				ft_endinsert_ina(t_push *push, int to_up, int nbr,
t_pile *little);
void				ft_insert_ina(t_push *push);
int					ft_startinsert_inb(t_push *push, int nbr, t_pile *little,
t_pile *pile);
void				ft_insert_inb(t_push *push);
int					ft_get_index(t_pile *pile);
int					ft_get_from_end(t_push *push, int from_end, int nbr);
int					ft_get_from_top(t_push *push, int from_start, int nbr);
t_pile				*ft_get_biggest(t_pile *pile);
void				ft_get_big_up(t_push *push);
int					ft_get_biggest_index(t_pile *pile);
#endif
