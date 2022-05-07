/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/07 18:12:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	d(t_args *lstargs)
{
	int	nbr;

	nbr = va_arg(lstargs->variatic_arg, int);
	lstargs->printable_arg = ft_itoa(nbr);
}


void	s(t_args *lstargs)
{
	int		printed;
	char	*s;


	s = va_arg(lstargs->variatic_arg, char *);
	printed = ft_strlen(s);
	ft_putstr(s, lstargs);
	lstargs->args_size += printed;
}


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
	//ft_call(test, lstargs);
	ft_call(ft_getfnc(lstargs), lstargs);
	ft_print_prefix(lstargs);
	ft_print_precision(lstargs);
	ft_putstr(lstargs->printable_arg, lstargs);
	//ft_call(test, lstargs);
	ft_reset_list(lstargs);
	return (0);
}
