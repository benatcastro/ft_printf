/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:30:00 by bena              #+#    #+#             */
/*   Updated: 2022/05/10 02:42:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_precision(t_args *lstargs)
{
	char	c;
	int		i;

	if (lstargs->precision_size < (int)ft_strlen(lstargs->printable_arg))
		return ;
	if (lstargs->precision_type == '0')
	{
		c = '0';
		i = (ft_strlen(lstargs->printable_arg) - lstargs->precision_size) * -1;
	}
	else if (lstargs->precision_type == '-')
	{
		c = ' ';
		i = ft_strlen(lstargs->printable_arg) + lstargs->precision_size;
	}
	//printf("SIZE: (%d)\n", i);
	//return ;
	while (i--)
		ft_putchar(c, lstargs);
}
