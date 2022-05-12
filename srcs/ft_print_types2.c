/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 06:12:13 by bena              #+#    #+#             */
/*   Updated: 2022/05/11 15:59:13 by becastro         ###   ########.fr       */
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
