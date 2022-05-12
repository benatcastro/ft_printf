/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:52 by becastro          #+#    #+#             */
/*   Updated: 2022/05/12 04:05:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(unsigned char c, t_args *lstargs)
{
	write(1, &c, 1);
	lstargs->args_size++;
}

void	ft_putstr(char *s, t_args *lstargs)
{
	size_t	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		lstargs->args_size += 6;
	}
	else if ((s[0] == 0 && s[1] == 0) && lstargs->type == 'c')
		ft_putchar(0, lstargs);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], lstargs);
		i++;
	}
}

void	*ft_getfnc(t_args *lstargs)
{
	if (lstargs->type == 'c')
		return (&c);
	else if (lstargs->type == 's')
		return (&s);
	else if (lstargs->type == 'p')
		return (&p);
	else if (lstargs->type == 'd')
		return (&d);
	else if (lstargs->type == 'i')
		return (&d);
	else if (lstargs->type == 'x')
		return (&x);
	else if (lstargs->type == 'X')
		return (&upper_x);
	else if (lstargs->type == '%')
		return (&percent);
	ft_putstr("TYPE ERROR\n", lstargs);
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
