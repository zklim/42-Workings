/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim < zhlim@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:05:30 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/20 17:58:03 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y)
{
	int	j;

	if (x < 0 || y < 0)
	{
		error_msg();
	}
	else
	{
		lines('/', '*', '\\', x);
		j = 0;
		while (j < (y - 2))
		{
			lines('*', ' ', '*', x);
			j++;
		}
		lines('\\', '*', '/', x);
	}
}

void	lines(char start, char mid, char end, int len)
{
	int	i;

	if (len > 0)
		ft_putchar(start);
	if (len > 2)
	{
		i = 2;
		while (i < len)
		{
			ft_putchar(mid);
			i++;
		}
	}
	if (len > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	error_msg(void)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
}
