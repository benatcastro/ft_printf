/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/04 02:57:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	d(t_args *lstargs)
{
	printf("%d", va_arg(lstargs->argument, int));
	// ft_putstr(ft_itoa(va_arg(lstargs->argument, int)));
}

void	s(t_args *lstargs)
{
	char	*s;

	s = lstargs->test;
	ft_putstr(s);
}

int	ft_print_argument(t_args *lstargs)
{
	ft_call(ft_getfnc(lstargs->type), lstargs);
	return (0);
}
