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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		count;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(strs));
	if (!(str))
		return (NULL);
	count = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			str[count++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			str[count++] = sep[j++];
	}
	str[count] = '\0';
	return (str);
}

int main(void)
{
	char *a[5];

	a[0] = "Hello";
	a[1] = "World";
	a[2] = "What";
	a[3] = "The";
	a[4] = "Good";
	printf ("%s\n", ft_strjoin(5, a, "+-_"));
	return (0);
}
