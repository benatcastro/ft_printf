/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:04:19 by bena              #+#    #+#             */
/*   Updated: 2022/05/02 14:48:40 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_args	*ft_getflags(char *arg)
{
	size_t	i;
	t_args	*lstargs;

	lstargs = malloc(sizeof(t_args));
	i = -1;
	while (arg[i++])
	{
		if (!is_in_types(arg[i]))
		{
			lstargs->type = arg[i];
			break ;
		}
		if ((arg[i] == '+') || (arg[i] == '#'))
			lstargs->prefix = arg[i];
		if (arg[i] == ' ' && !((lstargs->prefix == '#')
				|| lstargs->prefix == '+'))
			lstargs->prefix = ' ';
	}
	return (lstargs);
}
