/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:37:54 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/12 15:39:04 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/user_functions.h"
#include <stdlib.h>

int	main(void)
{
	int		i = 32;
	while (i < 127)
		ft_putchar(i++);
	return (EXIT_SUCCESS);
}
