/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim < zhlim@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:12:26 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/21 18:20:03 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	error_msg(void)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
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

void	rush(int x, int y)
{
	int	j;

	if (x < 0 || y < 0)
	{
		error_msg();
	}
	else
	{
		lines('A', 'B', 'C', x);
		j = 0;
		while (j < (y - 2))
		{
			lines('B', ' ', 'B', x);
			j++;
		}
		lines('C', 'B', 'A', x);
	}
}
