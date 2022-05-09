/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/05/09 19:49:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(char *str, ...)
{
	size_t	i;
	t_args	*lstargs;
	char	*arg;

	lstargs = malloc(sizeof(t_args));
	va_start(lstargs->variatic_arg, str);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			arg = ft_trim_arg(&str[i + 1]);
			lstargs->arg = arg;

			ft_print_argument(ft_getflags(lstargs));
			i += ft_is_arg (&str[i + 1]);
			free(arg);
		}
		else
			ft_putchar(str[i], lstargs);
	}
	va_end(lstargs->variatic_arg);
	free(lstargs);
	return (lstargs->args_size);
}
