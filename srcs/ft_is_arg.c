/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:46:34 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 14:24:49 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_is_arg(const char *s)
{
	int		sizeof_arg;
	size_t	i;

	i = -1;
	sizeof_arg = 0;
	while (s[i++])
	{
		while ((s[i] == ' ' && *s) || is_in_flags(s[i]) == 0)
		{
			i++;
			sizeof_arg++;
		}
		if (is_in_types(*s))
		{
			return (sizeof_arg + 1);
		}
	}
	return (-1);
}

int	is_in_types(char c)
{
	char	*types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (*types == c)
			return (0);
		types++;
	}
	return (1);
}

int	is_in_flags(char c)
{
	char	*flags;

	flags = "-0.#+ ";
	while (*flags)
	{
		if (*flags == c)
			return (0);
		flags++;
	}
	return (1);
}
