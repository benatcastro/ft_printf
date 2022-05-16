/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:37:08 by becastro          #+#    #+#             */
/*   Updated: 2022/05/16 11:31:10 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_first_param(t_args *lstargs)
{
	char		*full_arg;
	char		*aux;
	char		*aux2;
	int			i;

	if (lstargs->arg[0] != '-' && (!ft_isdigit(lstargs->arg[0])
			|| lstargs->arg[0] == '0'))
		return ;
	//printf("FIRST ARG %s\n", lstargs->arg);
	full_arg = ft_strdup(lstargs->arg);
	i = 0;
	if (full_arg[0] == '-')
	{
		//aux2 = ft_strdup(full_arg);
		lstargs->first_params.sign = '-';
		aux2 = ft_substr(full_arg, 1, ft_strlen(full_arg));
		free(full_arg);
		full_arg = ft_strdup(aux2);
		free(aux2);
	}
	while ((!is_in_precision(full_arg[i]) && full_arg[i] != '.')
		|| ft_isdigit(full_arg[i]))
		i++;
	aux = ft_substr(full_arg, 0, i);
	lstargs->first_params.nbr = ft_atoi(aux);
	free(aux);
	aux = ft_substr(full_arg, i, ft_strlen(full_arg) - i);
	//printf("aux |%s| full |%s| arg |%s|\n", aux, full_arg, lstargs->arg);
	//printf("i = (%d)\n", i);
	free(lstargs->arg);
	lstargs->arg = ft_strdup(aux);
	free(aux);
	free(full_arg);
}
