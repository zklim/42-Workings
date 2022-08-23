#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int a;
	int *nbr;

	a = 21;
	nbr = &a;
	write(1, &a, 1);
	ft_ft(nbr);
	write(1, &a, 1);
}
