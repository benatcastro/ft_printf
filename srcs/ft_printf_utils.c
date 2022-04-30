/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:52 by becastro          #+#    #+#             */
/*   Updated: 2022/04/30 16:29:08 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void ft_putchar(unsigned char c)
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
}
