/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:39 by bena              #+#    #+#             */
/*   Updated: 2022/05/11 06:09:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	c(t_args *lstargs)
{
	char	c;
	char	*c_str;

	c = va_arg(lstargs->variatic_arg, int);
	c_str = malloc(2);
	c_str[0] = c;
	c_str[1] = '\0';
	lstargs->printable_arg = c_str;
}

void	s(t_args *lstargs)
{
	char	*s;

	s = ft_strdup(va_arg(lstargs->variatic_arg, char *));
	lstargs->printable_arg = s;
}

void	x(t_args *lstargs)
{
	char	*hexa_nbr;

	hexa_nbr = ft_itoa_hexa(va_arg(lstargs->variatic_arg, int));
	lstargs->printable_arg = hexa_nbr;

}

void	upper_x(t_args *lstargs)
{
	char	*hexa_nbr;
	int		i;

	i = -1;
	hexa_nbr = ft_itoa_hexa(va_arg(lstargs->variatic_arg, int));
	while (hexa_nbr[++i])
		hexa_nbr[i] = ft_toupper(hexa_nbr[i]);
	lstargs->printable_arg = hexa_nbr;

}

void	d(t_args *lstargs)
{
	int	nbr;

	nbr = va_arg(lstargs->variatic_arg, int);
	lstargs->printable_arg = ft_itoa(nbr);
}
