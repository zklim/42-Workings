#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int i;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab[0]);
}

int	main(void)
{
	int	a[] = {1, 4, 6, 7, 9, 2};
	int	b = 5;

	printf("%d\n", max(a, b));
}
