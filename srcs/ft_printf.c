/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/04/27 07:55:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/printf.h"

int ft_printf(char *str, ...)
{
	va_list argptr;
	va_start(argptr, str);
	size_t	i;
	i = 0;
	while (str[i++])
	{

		if (ft_is_arg(*str + i) != 0 && str[i - 1] == '%')
		{
			i += ft_is_arg(str + 1);
			// ft_putstr("type arg: ");
			// ft_putchar(ft_is_arg(str + 1));
		}
		else
			ft_putchar(str[i]);
	}
	va_end(argptr);

	return (1);
}
