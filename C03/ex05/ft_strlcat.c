/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:48:55 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/31 19:26:02 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	count = 0;
	while (dest[i] != '\0')
		i++;
	while (src[count] != '\0')
		count++;
	count += i;
	while (src[j] != '\0')
	{
		if (i < size - 1)
			dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (count);
}

int	main(void)
{
	char *a = "asdfg";
	char *b = "qwert";

	printf("%lu\n", strlcat(a, b, 3));
	printf("%u\n", ft_strlcat(a, b, 3));
}
