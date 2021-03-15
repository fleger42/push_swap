#include "../includes/checker.h"

int		ft_size_pile(t_pile *pile)
{
	t_pile *actual;

	actual = pile;
	int size;

	size = 0;
	while(actual)
	{
		size++;
		actual = actual->next;
	}
	return (size);
}

void	ft_instruction(t_push *push)
{
	char *line;

	line = NULL;
	while(get_next_line(0, &line) > 0)
	{
		if(ft_strcmp(line, "pa") == 0)
			ft_push_a(push);
		else if(ft_strcmp(line, "pb") == 0)
			ft_push_b(push);
		else if(ft_strcmp(line, "sa") == 0)
			ft_sa(push);
		else if(ft_strcmp(line, "sb") == 0)
			ft_sb(push);
		else if(ft_strcmp(line, "ss") == 0)
		{
			ft_sa(push);
			ft_sb(push);
		}
		else if(ft_strcmp(line, "ra") == 0)
			ft_ra(push);
		else if(ft_strcmp(line, "rb") == 0)
			ft_rb(push);
		else if(ft_strcmp(line, "rr") == 0)
		{
			ft_ra(push);
			ft_rb(push);
		}
		else if(ft_strcmp(line, "rra") == 0)
			ft_rra(push);
		else if(ft_strcmp(line, "rrb") == 0)
			ft_rrb(push);
		else if(ft_strcmp(line, "rrr") == 0)
		{
			ft_rrb(push);
			ft_rra(push);
		}
		free(line);
		line = NULL;
	}
}

int main(int ac, char **av)
{
	t_push *push;

	push = ft_malloc_t_push(ac, av);
	ft_verif(push);
	ft_pile_create_a(push, av);
	ft_instruction(push);
	if(ft_sorted(push->first_a) == 1 && push->first_b == NULL)
	{
		printf("OK\n");
		printf("sorted in %d\n", push->etape);
		exit (0);
	}
	else
	{
		printf("KO\n");
		exit (1);
	}
}
