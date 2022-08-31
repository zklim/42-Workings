/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim < zhlim@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:43:29 by zhlim             #+#    #+#             */
/*   Updated: 2022/08/31 13:42:33 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_non_printable(char *str)
{
	int		a;
	int		b;
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			a = str[i] / 16;
			b = str[i] % 16;
			write(1, "\\", 1);
			write(1, &hex[a], 1);
			write(1, &hex[b], 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
