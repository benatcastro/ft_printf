/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/13 13:42:12 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test(t_args *lstargs)
{
	printf("\nType: (%c)\nPrefix (%c)\nPre_Type(%c)\nPre_size (%d)\nValid (%d)\n",
		lstargs->type,
		lstargs->prefix,
		lstargs->precision_type,
		lstargs->precision_size,
		lstargs->valid_arg);
	ft_reset_list(lstargs);
}

int	ft_print_argument(t_args *lstargs)
{
	int	i;

	ft_call(ft_getfnc(lstargs), lstargs);
	ft_print_prefix(lstargs);
	i = lstargs->first_params.nbr
		- ft_strlen(lstargs->printable_arg) + 1;
	if (lstargs->first_params.sign != '-')
	{
		while (i-- > 0)
			ft_putchar(' ', lstargs);
		ft_final_print(lstargs);
	}
	else if (lstargs->first_params.sign == '-')
	{
		ft_final_print(lstargs);
		while (i-- > 0)
			ft_putchar(' ', lstargs);
	}
	ft_reset_list(lstargs);
	return (0);
}

void	ft_final_print(t_args *lstargs)
{
	if (lstargs->precision_type == '-')
	{
		ft_putstr(lstargs->printable_arg, lstargs);
		ft_print_precision(lstargs);
	}
	else
	{
		ft_print_precision(lstargs);
		ft_putstr(lstargs->printable_arg, lstargs);
	}
}
