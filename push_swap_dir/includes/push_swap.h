#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# define ALPHA 1
# define BETA 0

typedef struct	s_push
{
	int 			ac;
	char 			**av;
	int				*sorted_tab;
	int 			etape;
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
}				t_push;

typedef struct	s_pile
{
	int				nbr;
	struct s_pile	*prev;
	struct s_pile	*next;
}				t_pile;
void	ft_five(t_push *push);
void	ft_rrb(t_push *push); //reverse rotate b : shift down all elements of stackaby 1. The last_b elementbecomes the first_a one.
void	ft_rb(t_push *push); //rotate b : shift up all elements of stackaby 1. The first_b element becomesthe last_a one.
void		ft_print_t_pile(t_pile *pile, t_pile *pile2);
t_pile		*ft_get_actual_pile(int nbr);
void		ft_pile_create_a(t_push	*push, char **av);
void		ft_pile_create_first(t_push	*push, int nbr, int ver);
void		ft_free_pile(t_pile *pile);
int		ft_sorted(t_pile *pile);
void		ft_verif(t_push *push);
t_push		ft_create_t_push(int ac, char **av);
t_push		*ft_malloc_t_push(int ac, char **av);
void		ft_free_t_push(t_push *to_free);
void		ft_insert_after(t_pile *pile, t_pile *new);
void		ft_insert_before(t_push *push, t_pile *pile, t_pile *new, int ver);
void		ft_remove_pile(t_push *push, t_pile *to_supp, int ver);
t_pile		*ft_dup_pile(t_pile *pile);
void	ft_big(t_push *push);
int		ft_get_biggest_index(t_pile *pile);
t_pile	*ft_get_biggest(t_pile *pile);
t_pile	*ft_get_tiniest(t_pile *pile);
void	ft_sa(t_push *push);
void	ft_rra(t_push *push);
void	ft_ra(t_push *push);
void	ft_push_b(t_push *push);
void	ft_push_a(t_push *push);
void	ft_hardcode(t_push *push, int big_index, int little_index);
void	ft_three(t_push *push);
int		ft_size_pile(t_pile *pile);
void	ft_get_little_up(t_push *push);
void	ft_little(t_push *push);
#endif