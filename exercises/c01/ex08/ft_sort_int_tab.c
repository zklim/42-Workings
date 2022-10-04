/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:32:05 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/29 17:32:57 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	size--;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
	}
}

void	ft_check(int *tab, int size)
{
	int	i;
	int	e;

	i = 0;
	size--;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			e = 1;
		}
		i++;
	}
	if (e == 1)
	{
		size++;
		ft_swap(tab, size);
		ft_check(tab, size);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_swap(tab, size);
	ft_check(tab, size);
}
