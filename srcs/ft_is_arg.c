/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:46:34 by becastro          #+#    #+#             */
/*   Updated: 2022/05/02 08:40:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_is_arg(const char *s)
{
	char	*types;
	int		sizeof_arg;

	types = "cspdiuxX%";
	sizeof_arg = 0;
	while (*s)
	{
		while (*s == ' ' && *s)
		{
			s++;
			sizeof_arg++;
		}
		if (is_in_types(*s, types) == 1)
		{
			ft_putstr("ARG");
			return (sizeof_arg + 1);
		}
	}
	return (0);
}

int	is_in_types(char s, const char *types)
{
	while (*types)
	{
		if (*types == s)
			return (1);
		types++;
	}
	return (0);
}
