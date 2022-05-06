/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:04:19 by bena              #+#    #+#             */
/*   Updated: 2022/05/06 19:15:11 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_args	*ft_getflags(char *arg, t_args *lstargs)
{
	size_t	i;

	i = -1;
	while (arg[i++])
	{
		if (!is_in_prefix(arg[i]))
			ft_get_prefix(lstargs, arg[i]);
		else if (!is_in_precision(arg[i]))
			ft_get_precision(lstargs, &arg[i]);
		else if (!is_in_types(arg[i]))
		{
			lstargs->type = arg[i];
			//printf("precision arg: %s", arg);
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
	printf("ARG TEST: %s\n", &arg[i++]);
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
