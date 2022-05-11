/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/11 14:07:35 by becastro         ###   ########.fr       */
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
	//c(lstargs);
	//ft_call(test, lstargs);
	//return (0);
	//printf("Type (%c), fncP (%p)\n", lstargs->type, ft_getfnc(lstargs));
	ft_call(ft_getfnc(lstargs), lstargs);
	ft_print_prefix(lstargs);
	if (lstargs->precision_type == '-')
	{
		ft_putstr(lstargs->printable_arg, lstargs);
		ft_print_precision(lstargs);
	}
	else
	{
		ft_print_precision(lstargs);
		//printf("%s", lstargs->printable_arg);
		ft_putstr(lstargs->printable_arg, lstargs);
	}
	//ft_call(test, lstargs);
	ft_reset_list(lstargs);
	return (0);
}
