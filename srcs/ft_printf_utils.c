/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:52 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 02:37:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		ft_putchar(s[i]);
	}
	//write(1, &s, ft_strlen(s));
}

void	*ft_getfnc(char c)
{
	if (c == 'd')
		return (&d);
	else
		return (0);
}

void	ft_call(void (*f)(t_args), t_args *lstargs)
{
	(*f)(*lstargs);
}

