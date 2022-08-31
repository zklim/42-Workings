#include <unistd.h>

void	ft_write(int nb)
{
	char *nbr;
	int	i;

	nbr = "";
	i = 0;
	while (nb)
	{
		nbr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	if (sizeof(nb) <= sizeof(int))
	{
		if (nb == 0)
			write(1, "0", 1);
		if (nb > 0)
			ft_write(nb);
		if (nb < 0)
		{
			nb *= n;
			write(1, "-", 1);
			ft_write(nb);
		}
	}
}

int	main(void)
{
	int	a;

	a = 1234586;
	ft_putnbr(a);
}
