/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:46:23 by bena              #+#    #+#             */
/*   Updated: 2022/05/12 03:59:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_prefix(t_args *lstargs)
{
	if (lstargs->prefix)
	{
		if ((lstargs->type == 'd' || lstargs->type == 'i')
			&& lstargs->prefix == '+')
		{
			if (lstargs->printable_arg[0] == '-')
				return ;
		}
		else
		{
			ft_putchar(lstargs->prefix, lstargs);
			lstargs->precision_size--;
		}
		if ((lstargs->type == 'x' || lstargs->type == 'X')
			&& lstargs->prefix == '#')
		{
			ft_putstr("0x", lstargs);
			lstargs->precision_size -= 2;
		}
	}
}
