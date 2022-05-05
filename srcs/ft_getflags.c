/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:04:19 by bena              #+#    #+#             */
/*   Updated: 2022/05/05 19:18:20 by becastro         ###   ########.fr       */
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
	size_t	j;

	i = -1;
	while (arg[i++])
	{
		if (arg[i] == '0')
		{
			lstargs->precision_type = '0';
			i++;
			j = i;
			while (arg[j] && ft_isdigit(arg [j]))
			{
				j++;
			}
			printf("atoi: %d\n") ft_atoi(ft_substr(&arg[i], 0, j - i));
		}
	}
}
