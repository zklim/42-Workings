#include <stdio.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i;
	unsigned char result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (result);
}

int	main(void)
{
	char a;

	a = 1;
	printf("%c\n", reverse_bits(a));
	aff_bin(a);
	aff_bin(reverse_bits(a));
}
