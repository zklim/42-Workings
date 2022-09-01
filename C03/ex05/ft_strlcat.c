/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:48:55 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/01 12:56:23 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	c1;
	unsigned int	c2;

	i = 0;
	c1 = 0;
	c2 = 0;
	while (src[c2++])
		;
	if (size == 0)
		return (c2 - 1);
	while (dest[c1++])
		;
	if (size <= c1)
		return (size + c2 - 1);
	while (src[i++])
		dest[c1 + i] = src[i];
	dest[c1 + i] = '\0';
	return (c1 + c2 - 2);
}

int	main(void)
{
	char a[15] = "Hell";
	char b[] = "World";
	printf("%u %s\n", ft_strlcat(a, b, 10), a);
	//printf("%lu %s\n", strlcat(a, b, 10), a);
}
