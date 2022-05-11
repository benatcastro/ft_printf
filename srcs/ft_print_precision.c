/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:30:00 by bena              #+#    #+#             */
/*   Updated: 2022/05/11 12:46:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_precision(t_args *lstargs)
{
	char	c;
	int		i;

	i = 0;
	if (lstargs->precision_type == '.' && lstargs->type == 's')
		//printf("DOT FNC\n");
		ft_call(ft_print_dot, lstargs);
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
	while (i--)
		ft_putchar(c, lstargs);
}

void	ft_print_dot(t_args *lstargs)
{
	char	*src;
	char	*test;

	src = lstargs->printable_arg;
	test = ft_substr(src, 0, lstargs->precision_size);
	free(lstargs->printable_arg);
	//printf("PRINTF TEST (%s)\n", test);
	lstargs->printable_arg = test;
	//ft_putstr(test, lstargs);
	//ft_putchar('\n', lstargs);
}
