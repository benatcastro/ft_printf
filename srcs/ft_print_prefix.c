/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:46:23 by bena              #+#    #+#             */
/*   Updated: 2022/05/09 22:44:37 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_prefix(t_args *lstargs)
{
	if (lstargs->prefix)
	{
		ft_putchar(lstargs->prefix, lstargs);
		lstargs->precision_size--;
	}
}
