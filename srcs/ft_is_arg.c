/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:46:34 by becastro          #+#    #+#             */
/*   Updated: 2022/04/27 07:45:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int ft_is_arg(const char *s)
{
	char	*types;
	int		sizeof_arg;
	// printf("\nargto check: %s\n", s);
	types = "cspdiuxX%";
	while (*s)
	{
		while(*s == ' ' && *s)
		{
			s++;
			sizeof_arg++;
		}
				// printf("checking char: %c\n", *s);
		if (is_in_types(*s, types) == 1)
		{
			ft_putstr("IS ARG");
			return (sizeof_arg);
		}
		s++;
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
