/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/05/15 00:09:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	size_t	i;
	t_args	*lstargs;
	char	*arg;
	char	*str;
	int		aux;

	str = (char *)s;
	lstargs = ft_calloc(1, sizeof(t_args));
	va_start(lstargs->variatic_arg, s);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			arg = ft_trim_arg(&str[i + 1]);
			lstargs->arg = ft_strdup(arg);
			free (arg);
			ft_print_argument(ft_getflags(lstargs));
			i += ft_is_arg (&str[i + 1]);
		}
		else
			ft_putchar(str[i], lstargs);
	}
	va_end(lstargs->variatic_arg);
	aux = lstargs->args_size;
	free(lstargs);
	return (aux);
}
