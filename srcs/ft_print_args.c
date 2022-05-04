/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/04 15:04:43 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	d(t_args *lstargs)
{
	int	nbr;

	nbr = va_arg(lstargs->argument, int);
	if (lstargs->prefix == ' ')
	{
		ft_putchar(' ', lstargs);
	}
	else if (lstargs->prefix == '+' && nbr >= 0)
	{
		ft_putchar('+', lstargs);
	}
	ft_putstr(ft_itoa(nbr), lstargs);
}

void	s(t_args *lstargs)
{
	int		printed;
	char	*s;


	s = va_arg(lstargs->argument, char *);
	printed = ft_strlen(s);
	ft_putstr(s, lstargs);
	lstargs->args_size += printed;
}

int	ft_print_argument(t_args *lstargs)
{
	ft_call(ft_getfnc(lstargs), lstargs);
	return (0);
}
