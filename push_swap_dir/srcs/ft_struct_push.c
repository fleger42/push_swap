#include "../includes/push_swap.h"

t_push		ft_create_t_push(int ac, char **av)
{
	t_push	push;
	push.ac = ac;
	push.av = av;
	push.first_b = NULL;
	push.last_b = NULL;
	push.etape = 0;
	return (push);
}

t_push		*ft_malloc_t_push(int ac, char **av)
{
	t_push	*push;

	push = (t_push*)malloc(sizeof(t_push));
	*push = ft_create_t_push(ac, av);
	return (push);
}

void		ft_free_t_push(t_push *to_free)
{
	free(to_free);
}
