#include <stdio.h>

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_atoi(char *str, char *to_find)

{
	int	sign;
	int	ret;
	int	i;

	sign = 1;
	ret = 0;
	i = 0;
	while (str[i] < '0' || str[i] > '9')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
		}
		if (str[i] == '\0')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (str[i] - '0') + (ret * 10);
		i++;
	}
	return (ret * sign);
}
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if (str[i] == to_find[j])
			{
				res += j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int ft_atoi_base(char *str, char *base)
{
	int	res;
	int	blen;
	int	ret;

	blen = ft_checkbase(base);
	if (blen > 1)
	{
		res = ft_atoi(str, base);
		while (res)
		{
			ret = res % 10;
			res /= 10;
		}
		return (ret);
	}
	return (0);
}

int	main(void)
{
	char a[] = "ab";
	char b[] = "0123456789abcdef";

	printf("%d\n", ft_atoi_base(a, b));
}
