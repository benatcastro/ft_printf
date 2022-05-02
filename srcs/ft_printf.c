/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/05/02 13:02:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(char *str, ...)
{
	size_t	i;
	va_list	argptr;

	va_start(argptr, str);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && ft_is_arg (&str[i + 1]) != -1)
		{
			// printf("arg value: %d\n", ft_is_arg (&str[i + 1]));
			i += ft_is_arg (&str[i + 1]);
		}
		else
		{
			ft_putchar(str[i]);
		}
	}
	va_end(argptr);
	return (1);
}
