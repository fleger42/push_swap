#include "push_swap.h"

int		ft_sorted(t_pile *pile)
{
	int actual;

	while(pile)
	{
		actual = pile->nbr;
		if(pile->next != NULL && actual > pile->next->nbr)
		{
			printf("Not sorted\n");
			return (0);
		}
		pile = pile->next;
	}
	printf("Sorted\n");
	return (1);
}

void	ft_verif(t_push *push)
{
	if(push->ac < 2)
	{
		printf("Arg not specified\n");
		exit(1);
	}

}
