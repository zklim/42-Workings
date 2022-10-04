/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:33:38 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/16 15:33:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_size(int nb, int size)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb)
	{
		nb /= size;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb, char *base, int size)
{
	char	*res;
	int		count;
	int		tmp;
	int		i;

	i = 0;
	count = count_size(nb, size);
	res = (char *)malloc(sizeof(char) * count + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[i] = '-';
		nb *= -1;
	}
	while (nb)
	{
		i++;
		res[count - i] = base[nb % size];
		nb /= size;
	}
	res[count] = '\0';
	return (res);
}
