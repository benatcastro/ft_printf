/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:37:08 by becastro          #+#    #+#             */
/*   Updated: 2022/05/16 20:42:58 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_trim_minus(char	*arg, t_args *lstargs)
{
	char	*aux;

	lstargs->first_params.sign = '-';
	aux = ft_substr(arg, 1, ft_strlen(arg));
	free(arg);
	return (aux);

}

static void	ft_get_first_param(t_args *lstargs)
{
	char		*full_arg;
	char		*aux;
	int			i;

	full_arg = ft_strdup(lstargs->arg);
	i = 0;
	if (full_arg[0] == '-')
	{
		full_arg = ft_trim_minus(full_arg, lstargs);
	}
	while ((!is_in_precision(full_arg[i]) && full_arg[i] != '.')
		|| ft_isdigit(full_arg[i]))
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

//static	ft_print_pre

void	ft_get_field_width(t_args *lstargs)
{
	int	i;
	int	j;

	j = -1;
	while (lstargs->arg[++j])
	{
		if ((!ft_isdigit(lstargs->arg[j])
				&& lstargs->arg[j] != '-')
			&& lstargs->arg[j] != '.' && lstargs->arg[j] != 's')
			return ;
		else if (lstargs->arg[j] == '.' || lstargs->arg[j] == 's')
			break ;
	}
	if (lstargs->arg[j] == '.')
	{
		ft_get_first_param(lstargs);
		return ;
	}
	else if (lstargs->arg[0] != '-' && lstargs->arg[j] == 's')
	{
		ft_get_first_param(lstargs);
		i = lstargs->first_params.nbr - ft_strlen(lstargs->printable_arg);
	}
}
