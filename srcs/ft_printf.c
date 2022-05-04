/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 15:05:03 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(char *str, ...)
{
	size_t	i;
	va_list	argptr;
	t_args	*lstargs;

	lstargs = malloc(sizeof(t_args));
	va_start(lstargs->argument, str);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && ft_is_arg (&str[i + 1]) != -1)
		{
			ft_print_argument(ft_getflags(&str[i + 1], lstargs));
			i += ft_is_arg (&str[i + 1]);
		}
		else
		{
			ft_putchar(str[i], lstargs);
		}
	}
	va_end(argptr);
	return (lstargs->args_size);
}
