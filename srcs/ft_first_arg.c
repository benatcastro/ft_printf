/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:37:08 by becastro          #+#    #+#             */
/*   Updated: 2022/05/13 13:26:43 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_first_param(t_args *lstargs)
{
	char		*full_arg;
	char		*aux;
	int			i;

	full_arg = lstargs->arg;
	i = -1;
	if (full_arg[0] == '-')
	{
		lstargs->first_params.sign = '-';
		i++;
	}
	while (is_in_precision(full_arg[i]))
		i++;
	aux = ft_substr(full_arg, 0, i);
	lstargs->first_params.nbr = ft_atoi(aux);
	free(aux);
	aux = ft_substr(full_arg, i, ft_strlen(full_arg) - i);
	free(lstargs->arg);
	lstargs->arg = ft_strdup(aux);
	free(aux);
}

void	ft_print_first_param(t_f_width first_params, t_args *lstargs)
{
	while (first_params.nbr-- > 0)
		ft_putchar(' ', lstargs);
}
