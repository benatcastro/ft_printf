/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:52 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 15:28:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar(unsigned char c, t_args *lstargs)
{
	write(1, &c, 1);
	lstargs->args_size++;
}

void	ft_putstr(const char *s, t_args *lstargs)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		ft_putchar(s[i], lstargs);
	}
}

void	*ft_getfnc(t_args *lstargs)
{
	if (lstargs->type == 'd')
		return (&d);
	if (lstargs->type == 's')
		return (&s);
	else
		return (0);
}

void	ft_call(void (*f)(t_args*), t_args *lstargs)
{
	f(lstargs);
}
