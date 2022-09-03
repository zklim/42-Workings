#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb)
	{
		res = res * nb;
		nb -= 1;
	}
	return (res);
}

int	main(void)
{
	int	i;
	
	i = 0u;
	printf("%d\n%d\n", i, ft_iterative_factorial(i));
}
