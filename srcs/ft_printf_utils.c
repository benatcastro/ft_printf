/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:52 by becastro          #+#    #+#             */
/*   Updated: 2022/05/07 17:39:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar(unsigned char c, t_args *lstargs)
{
	write(1, &c, 1);
	lstargs->args_size++;
}

void	ft_putstr(const char *s, t_args *lstargs)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		ft_putchar(s[i], lstargs);
	}
}

void	*ft_getfnc(t_args *lstargs)
{

	if (lstargs->type == 'd')
		return (&d);
	if (lstargs->type == 's')
		return (&s);
	else
		return (0);
}

void	ft_call(void (*f)(t_args*), t_args *lstargs)
{
	f(lstargs);
}

char	*ft_trim_arg(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && is_in_types(str[i]))
		i++;
	return (ft_substr(str, 0, i + 1));
}

void	ft_reset_list(t_args *lstargs)
{
	lstargs->arg = 0;
	lstargs->type = 0;
	lstargs->prefix = 0;
	lstargs->precision_type = 0;
	lstargs->precision_size = 0;
	lstargs->valid_arg = 0;
	free(lstargs->printable_arg);
}
