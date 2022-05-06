/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/06 19:12:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	d(t_args *lstargs)
{
	int		nbr;
	char	*str;

	nbr = va_arg(lstargs->argument, int);
	str = ft_itoa(nbr);
	if (lstargs->prefix == ' ')
	{
		ft_putchar(' ', lstargs);
	}
	else if (lstargs->prefix == '+' && nbr >= 0)
	{
		ft_putchar('+', lstargs);
	}

	ft_putstr(str, lstargs);
	free(str);
}

void	s(t_args *lstargs)
{
	int		printed;
	char	*s;


	s = va_arg(lstargs->argument, char *);
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
}


int	ft_print_argument(t_args *lstargs)
{
	ft_call(test, lstargs);
	return (0);
}
