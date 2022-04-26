/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/04/26 19:16:29 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/printf.h"

int ft_printf(char *str, ...)
{
	va_list argptr;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{

			if (ft_is_arg(str) == 1)
				ft_putstr("ARG");
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(argptr);

	return (1);
}
