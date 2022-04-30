/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/04/30 16:41:20 by becastro         ###   ########.fr       */
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
		if (str[i] == '%')
		{
			i += ft_is_arg (&str[i + 1]);
			printf("I: %zu\n", i);
			// if (ft_strlen(str) > i)
			// 	i = ft_strlen(str);
		}
		else
		{
			// // ft_putstr("\nstring before: \n");
			// ft_putstr(&str[i]);
			// ft_putchar('(');
			ft_putchar(str[i]);
			// ft_putchar(')');
		}
	}
	va_end(argptr);
	return (1);
}
