#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line.h"
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
int		ft_size_pile(t_pile *pile);
void	ft_instruction(t_push *push);
void	ft_sb(t_push *push); //swap a : swap the first_a 2 elements at the top of stack a. Do nothing if there is only one or no elements).
void	ft_sa(t_push *push); //swap a : swap the first_a 2 elements at the top of stack a. Do nothing if there is only one or no elements).
void	ft_rrb(t_push *push); //reverse rotate b : shift down all elements of stackaby 1. The last_b elementbecomes the first_a one.
void	ft_rb(t_push *push); //rotate b : shift up all elements of stackaby 1. The first_b element becomesthe last_a one.
void	ft_rra(t_push *push);//reverse rotate a : shift down all elements of stackaby 1. The last_a elementbecomes the first_a one.
void	ft_ra(t_push *push); //rotate a : shift up all elements of stackaby 1. The first_a element becomesthe last_a one.
void	ft_push_b(t_push *push);
void	ft_push_a(t_push *push);
t_push		ft_create_t_push(int ac, char **av);
t_push		*ft_malloc_t_push(int ac, char **av);
void		ft_free_t_push(t_push *to_free);
void		ft_insert_after(t_pile *pile, t_pile *new);
void		ft_insert_before(t_push *push, t_pile *pile, t_pile *new, int ver);
void		ft_remove_pile(t_push *push, t_pile *to_supp, int ver);
t_pile		*ft_dup_pile(t_pile *pile);
void		ft_print_t_pile(t_pile *pile, t_pile *pile2);
t_pile		*ft_get_actual_pile(int nbr);
void		ft_pile_create_first(t_push	*push, int nbr, int ver);
void		ft_pile_create_a(t_push	*push, char **av);
void		ft_free_pile(t_pile *pile);
int		ft_sorted(t_pile *pile);
void	ft_verif(t_push *push);
#endif