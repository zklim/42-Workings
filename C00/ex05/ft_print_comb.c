/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim < zhlim@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:04:49 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/22 13:15:23 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(char q, char w, char e)
{
	write(1, &q, 1);
	write(1, &w, 1);
	write(1, &e, 1);
	if (q < '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	q;
	char	w;
	char	e;

	q = '0';
	while (q < '8')
	{
		w = q + 1;
		while (w < '9')
		{
			e = w + 1;
			while (e <= '9')
			{
				ft_print(q, w, e);
				e++;
			}
			w++;
		}
		q++;
	}
}
