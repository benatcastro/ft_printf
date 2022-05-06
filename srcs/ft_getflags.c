/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:04:19 by bena              #+#    #+#             */
/*   Updated: 2022/05/06 20:02:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_args	*ft_getflags(t_args *lstargs)
{
	size_t	i;

	i = -1;
	//printf("TEST:%s\n", lstargs->arg);

	while (lstargs->arg[++i])
	{
		if (!is_in_prefix(lstargs->arg[i]))
			ft_get_prefix(lstargs, lstargs->arg[i]);
		else if (!is_in_precision(lstargs->arg[i]))
			ft_get_precision(lstargs, &lstargs->arg[i]);
		else if (!is_in_types(lstargs->arg[i]))
		{
			lstargs->type = lstargs->arg[i];
			break ;
		}
	}

	return (lstargs);
}

void	ft_get_prefix(t_args *lstargs, char c)
{
	if ((c == '+') || (c == '#'))
		lstargs->prefix = c;
	if (c == ' ' && !((lstargs->prefix == '#')
			|| lstargs->prefix == '+'))
			lstargs->prefix = ' ';
}

void	ft_get_precision(t_args *lstargs, char *arg)
{
	size_t	i;

	i = -1;
	while (arg[i++] && !ft_isdigit(arg[i]))
	{
		if (arg[i] == '-')
			lstargs->precision_type = '-';
		else if (arg[i] && lstargs->precision_type != '-')
			lstargs->precision_type = '0';
	}
}

void	ft_get_precision_size(t_args *lstargs, char *str)
{
	(void)lstargs;
	(void)str;
// 			while (arg[j] && ft_isdigit(arg [j]))
// 				j++;
// 			if (!is_in_types(arg[j]))
// 				lstargs->valid_arg = 1;
// 			else
// 				lstargs->valid_arg = 0;

// 			size_c = ft_substr(&arg[i], 0, j - i);
// 			lstargs->precision_size = ft_atoi(size_c);
// 			free(size_c);
}
