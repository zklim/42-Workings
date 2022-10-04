/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:20:38 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/16 14:43:18 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	word_count(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == charset[j])
			j++;
		if (i == 0 && j == 0)
			count++;
		if (charset[j] == '\0' && str[i + j] > 32)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] != charset[0])
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != charset[0])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		word;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	word = word_count(str, charset);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == charset[j])
			j++;
		if (i == 0 && j == 0)
			res[k++] = ft_strdup(&str[0], charset);
		if (charset[j] == '\0' && str[i + j] > 32)
			res[k++] = ft_strdup(&str[i + j], charset);
		i++;
	}
	res[k] = '\0';
	return (res);
}
/*
int	main(int ac, char **av)
{
	char	**b;
	int		i;

	if (ac == 3)
		b = ft_split(av[1], av[2]);
	for (i = 0; b[i]; i++)
		printf("%s\n", b[i]);
}*/
