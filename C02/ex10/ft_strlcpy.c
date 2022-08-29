/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:19:07 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/27 14:23:57 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i < size)
		{
			dest[i] = src[i];
		}
		if (i == size)
		{
			dest[i] = '\0';
		}
		i++;
	}
	if (src[i] == '\0')
	{
		dest[i] = '\0';
	}
	return (i);
}
