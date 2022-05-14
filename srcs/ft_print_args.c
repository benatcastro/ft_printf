/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/15 00:29:48 by bena             ###   ########.fr       */
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

void	ft_width_print(t_args *lstargs)
{
	int	i;
	int	j;

	j = ft_strlen(lstargs->printable_arg) - lstargs->precision_size;
	// 	ft_print_precision(lstargs);
	i = lstargs->first_params.nbr
		- ft_strlen(lstargs->printable_arg);
	if (lstargs->first_params.nbr > (int)ft_strlen(lstargs->printable_arg))
		i++;
	if (lstargs->precision_size > 0)
		i += j;
	//printf("I = (%d) J = (%d) PRE SIZE (%d)\n", i, j, lstargs->precision_size);
	if (lstargs->first_params.sign != '-')
	{
		while (i-- > 0 && i)
			ft_putchar(' ', lstargs);
		ft_final_print(lstargs);
	}
	else if (lstargs->first_params.sign == '-')
	{
		ft_final_print(lstargs);
		while (i-- > 0)
			ft_putchar(' ', lstargs);
	}
}

int	ft_print_argument(t_args *lstargs)
{
	ft_call(ft_getfnc(lstargs), lstargs);
	ft_print_prefix(lstargs);

	if (lstargs->first_params.nbr)
		ft_width_print(lstargs);
	else
		ft_final_print(lstargs);

	ft_reset_list(lstargs);
	return (0);
}

