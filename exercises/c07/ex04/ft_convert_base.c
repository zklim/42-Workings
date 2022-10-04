/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:20:31 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/16 15:34:43 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nb, char *base, int size);
int		count_size(int nb, int size);

int	ft_check(char *base)
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

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str, char *base, int size)
{
	int	sign;
	int	res;
	int	i;
	int	index;

	sign = 1;
	res = 0;
	i = 0;
	index = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		index = ft_index(str[i], base);
		res = res * size + index;
		i++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size;
	int		size2;
	int		nb;
	char	*res;

	size = ft_check(base_from);
	size2 = ft_check(base_to);
	if (size > 1 && size2 > 1)
	{
		nb = ft_atoi(nbr, base_from, size);
		res = ft_itoa(nb, base_to, size2);
		return (res);
	}
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	char	*a;

	if (ac == 4)
	{
		a = ft_convert_base(av[1], av[2], av[3]);
		if (!a)
			printf("Error\n");
		else
			printf("%s\n", a);
	}
	return (0);
}*/
