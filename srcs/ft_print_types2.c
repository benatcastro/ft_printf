/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 06:12:13 by bena              #+#    #+#             */
/*   Updated: 2022/05/12 04:03:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	p(t_args *lstargs)
{
	int		pointer;
	char	*aux;
	char	*ptr;

	pointer = va_arg(lstargs->variatic_arg, unsigned long);
	aux = ft_itoa_hexa(pointer);
	ptr = ft_strjoin("0x", aux);
	lstargs->printable_arg = ptr;
	free(aux);
}

void	percent(t_args *lstargs)
{
	char	*c_str;

	c_str = malloc(2);
	c_str[0] = '%';
	c_str[1] = '\0';
	lstargs->printable_arg = c_str;
}
