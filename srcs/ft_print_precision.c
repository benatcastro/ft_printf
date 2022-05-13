/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:30:00 by bena              #+#    #+#             */
/*   Updated: 2022/05/13 02:57:41 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_precision(t_args *lstargs)
{
	int	i;

	i = 0;
	if (lstargs->precision_type == '.' && lstargs->type == 's')
		ft_call(ft_print_dot, lstargs);
	if (lstargs->precision_size < (int)ft_strlen(lstargs->printable_arg))
		return ;
	if (lstargs->precision_type == '0')
		ft_call(ft_print_zero, lstargs);
	else if (lstargs->precision_type == '-')
		ft_call(ft_print_minus, lstargs);
	i = lstargs->write_pre;
	while (i--)
		ft_putchar(lstargs->precision_char, lstargs);
}

void	ft_print_zero(t_args *lstargs)
{
	lstargs->precision_char = '0';
	lstargs->write_pre = (ft_strlen(lstargs->printable_arg)
			- lstargs->precision_size) * -1;
	ft_print_sign(lstargs);
}

void	ft_print_minus(t_args *lstargs)
{
	lstargs->precision_char = ' ';
	lstargs->write_pre = (ft_strlen(lstargs->printable_arg)
			- lstargs->precision_size) * -1;
	if ((lstargs->printable_arg[0] == 0
			&& lstargs->printable_arg[1] == 0) && lstargs->type == 'c')
		lstargs->write_pre = lstargs->precision_size - 1;
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

void	ft_print_sign(t_args *lstargs)
{
	char	*s;

	if (lstargs->printable_arg[0] == '-')
	{
		ft_putchar('-', lstargs);
		s = ft_substr(lstargs->printable_arg, 1,
				ft_strlen(lstargs->printable_arg) - 1);
		free(lstargs->printable_arg);
		lstargs->printable_arg = s;
	}
}
