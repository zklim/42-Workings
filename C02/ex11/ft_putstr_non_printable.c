#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char hex[] = "0123456789abcdef";
	char a;
	char b;
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			a = str[i] / 16;
			b = str[i] % 16;
			ft_putchar(hex[a]);
			ft_putchar(hex[b]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	(void) ac;
	ft_putstr_non_printable(av[1]);
}
