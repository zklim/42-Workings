/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:30:20 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/09 11:16:27 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_count(char **strs, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (!(res = (char *)malloc(sizeof(char) * (str_count(strs, size) + ft_strlen(sep) * (size - 1) + 1))))
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			res[k] = strs[i][j];
			k++;
			j++;
		}
		if (i < size - 1)
		{	j = 0;
			while (sep[j])
			{
				res[k] = sep[j];
				k++;
				j++;
			}
		}
		i++;
	}
	res[k] = 0;
	return (res);
}

int main(int ac, char **av)
{
	char 	*b;
	char	**a;

	a = &av[1];
	b = ft_strjoin((ac - 2), a, av[ac - 1]);
	printf("%s\n", b);
	return (0);
}
