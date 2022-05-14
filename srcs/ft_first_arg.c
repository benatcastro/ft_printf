/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:37:08 by becastro          #+#    #+#             */
/*   Updated: 2022/05/15 00:31:15 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_first_param(t_args *lstargs)
{
	char		*full_arg;
	char		*aux;
	int			i;

	if (lstargs->arg[0] != '-' && (!ft_isdigit(lstargs->arg[0])
			|| lstargs->arg[0] == '0'))
		return ;
	full_arg = ft_strdup(lstargs->arg);
	i = 0;
	if (full_arg[0] == '-')
	{
		lstargs->first_params.sign = '-';
		full_arg++;
	}
	while (ft_isdigit(full_arg[i]))
		i++;
	while (!is_in_precision(full_arg[i]) && full_arg[i] != '.')
		i++;
	aux = ft_substr(full_arg, 0, i);
	lstargs->first_params.nbr = ft_atoi(aux);
	free(aux);
	aux = ft_substr(full_arg, i, ft_strlen(full_arg) - i);
	free(lstargs->arg);
	lstargs->arg = ft_strdup(aux);
	free(aux);
	free(full_arg);
}
