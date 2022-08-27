#include <stdio.h>
#include <stdlib.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i < size)
		{
			dest[i] = src[i];
		}
		if (i == size)
		{
			dest[i] = '\0';
		}
		i++;
	}
	if (src[i] == '\0')
	{
		dest[i] = '\0';
	}
	return (i);
}

int	main(int ac, char **av)
{
	(void)ac;
	unsigned int	a;
	int	b;

	b = atoi(av[3]);
	a = ft_strlcpy(av[1], av[2], b);
	printf("dest : %s\nsrc count : %u\n", av[1], a);

}
