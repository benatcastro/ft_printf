/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:46:34 by becastro          #+#    #+#             */
/*   Updated: 2022/04/26 19:14:20 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int ft_is_arg(const char *s)
{
	char	*types;

	printf("is arg str: %s\n", s);
	types = "cspdiuxX%";
	while (*s && *s == ' ')
	{
		if (is_in_types(*s, types) == 1)
			return (1);
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
