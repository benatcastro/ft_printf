/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:30:00 by bena              #+#    #+#             */
/*   Updated: 2022/05/09 22:59:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_precision(t_args *lstargs)
{
	char	c;
	int		i;
	int		j;

	if (lstargs->precision_type == '0')
		c = '0';
	else
		c = ' ';
	//printf("SIZE: (%d)", lstargs->precision_size);
	i = ft_to_positive(lstargs->precision_size
			+ ft_strlen(lstargs->printable_arg));
	j = 0;
	while (j < i)
	{
		ft_putchar(c, lstargs);
		j++;
	}
}

int	ft_to_positive(int nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		return (nbr);
	}
	return (nbr);
}
