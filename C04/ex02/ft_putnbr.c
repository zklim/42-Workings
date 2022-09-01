/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim < zhlim@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:06:24 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/01 13:06:41 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int nb)
{
	char	nbr[10];
	int		i;

	i = 0;
	while (nb)
	{
		nbr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i--)
		write(1, &nbr[i], 1);
}

void	ft_putnbr(int nb)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	if (nb <= 2147483647)
	{
		if (nb == 0)
			write(1, "0", 1);
		if (nb > 0)
			ft_write(nb);
		if (nb < 0)
		{
			nb *= n;
			write(1, "-", 1);
			ft_write(nb);
		}
	}
}
