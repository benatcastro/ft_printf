/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:47:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/11 05:45:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_char_to_s(char c)
{
	char	*s;

	s = malloc(2);
	s[0] = c;
	s[1] = 0;
	return (s);
}

char	*ft_itoa_hexa(long long nbr)
{
	t_hexa_data	*hexa_data;
	char		*return_str;

	hexa_data = malloc(sizeof(hexa_data));
	hexa_data->i = 0;
	hexa_data->check = 0;
	ft_to_hexa(nbr, hexa_data);
	hexa_data->check = 1;
	hexa_data->hexa_str = malloc(hexa_data->len);
	ft_to_hexa(nbr, hexa_data);
	return_str = ft_strdup(hexa_data->hexa_str);
	free(hexa_data->hexa_str);
	free(hexa_data);
	return (return_str);
}

void	ft_to_hexa(unsigned long long nbr, t_hexa_data *hexa_data)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_to_hexa(nbr / 16, hexa_data);
		ft_to_hexa(nbr % 16, hexa_data);
	}
	else
	{
		nbr += 48;
		if (nbr > '9')
			nbr = base[nbr - 48];
		if (hexa_data->check == 0)
			hexa_data->len++;
		else if (hexa_data->check == 1)
		{
			hexa_data->hexa_str[hexa_data->i] = nbr;
			hexa_data->i++;
		}
	}
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
