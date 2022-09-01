/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:00:02 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/01 19:00:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_write(int nbr, char *base, int i)
{
	char	print[20];
	int		j;

	j = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	while (nbr)
	{
		print[j] = base[nbr % i];
		nbr /= i;
		j++;
	}
	while (j--)
		write(1, &print[j], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = ft_check(base);
	if (i > 0)
		ft_write(nbr, base, i);
}
