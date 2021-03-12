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
	int ac;
	char **av;
	struct s_pile	*first_a;
	struct s_pile	*last_a;
	struct s_pile	*first_b;
	struct s_pile	*last_b;
}				t_push;

typedef struct	s_pile
{
	int				nbr;
	struct s_pile	*prev;
	struct s_pile	*next;
}				t_pile;
void		ft_print_t_pile(t_pile *pile, t_pile *pile2);
t_pile		*ft_get_actual_pile(int nbr);
void		ft_pile_create_a(t_push	*push, char **av);
void		ft_pile_create_b(t_push	*push, int nbr);
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
#endif