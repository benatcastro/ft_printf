/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:46:34 by becastro          #+#    #+#             */
/*   Updated: 2022/05/02 13:14:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_is_arg(const char *s)
{
	int		sizeof_arg;
	size_t	i;

	i = 0;
	sizeof_arg = 0;
	while (s[i++])
	{
		while (s[i] == ' ' && *s)
			sizeof_arg++;
		if (is_in_types(*s) == 1)
		{
			return (sizeof_arg + 1);
		}
	}
	return (-1);
}

int	is_in_types(char s)
{
	char	*types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (*types == s)
			return (1);
		types++;
	}
	return (0);
}
