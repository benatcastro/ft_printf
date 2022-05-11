/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:46:23 by bena              #+#    #+#             */
/*   Updated: 2022/05/11 14:10:56 by becastro         ###   ########.fr       */
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
	}
}
