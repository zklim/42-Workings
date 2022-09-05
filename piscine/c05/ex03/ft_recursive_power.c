/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:45:20 by zhlim             #+#    #+#             */
/*   Updated: 2022/09/05 11:45:28 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	fix;

	fix = nb;
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else if (power > 1)
		return (fix * ft_recursive_power(fix, power - 1));
	else
		return (0);
}
