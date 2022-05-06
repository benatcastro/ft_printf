/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:30:00 by bena              #+#    #+#             */
/*   Updated: 2022/05/06 21:10:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_print_precision(t_args *lstargs)
{
	char	c;
	int		i;
	int		j;

	if (lstargs->precision_type == '0')
		c = '0';
	else
		c = ' ';
	i = lstargs->precision_size - lstargs->arg_len;
	j = 0;
	while (j < i)
	{
		ft_putchar(c, lstargs);
		j++;
	}

}
