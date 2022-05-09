/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:04:19 by bena              #+#    #+#             */
/*   Updated: 2022/05/09 19:48:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

	while (lstargs->arg[++i] && (!ft_isdigit(lstargs->arg[i]
				|| lstargs->arg[i] == '0')))
	{
		if (arg[i] == '-')
		{
			lstargs->precision_type = '-';
			break ;
		}
		else if (arg[i] && lstargs->precision_type != '-')
		{
			lstargs->precision_type = '0';
			break ;
		}
	}
	ft_get_precision_size(lstargs, &lstargs->arg[i + 1]);
}

void	ft_get_precision_size(t_args *lstargs, char *str)
{
	size_t	i;
	char	*size_c;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	//printf("char: (%c)", str[i]);
	if (!is_in_types(str[i]))
		lstargs->valid_arg = 1;
	else
		lstargs->valid_arg = 0;
	size_c = ft_substr(str, 0, i);
	// printf("size_c (%s)\n", size_c);
	lstargs->precision_size = ft_atoi(size_c);
	free(size_c);
}
