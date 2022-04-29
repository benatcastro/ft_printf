/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/04/28 09:12:10 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/printf.h"

int	ft_printf(char *str, ...)
{
	size_t	i;

	va_list	argptr;
	va_start(argptr, str);

	i = 0;
	while (str[i++])
	{
		if (ft_is_arg(*str + i) != 0 && str[i - 1] == '%')
		{
			i += ft_is_arg(str + 1);
			// ft_putstr("type arg: ");
			if (ft_strlen(str) > i)
				ft_strlen()
			// ft_putchar(ft_is_arg(str + 1));
		}
		else
			ft_putchar(str[i]);
	}
	va_end(argptr);
	return (1);
}
