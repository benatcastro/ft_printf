/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:47:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/12 22:05:09 by becastro         ###   ########.fr       */
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

char	*ft_itoa_base(long long nbr, int base)
{
	t_nbr_data	nbr_data;
	char		*return_str;

	// nbr_data = malloc(sizeof(nbr_data));

	nbr_data.i = 0;
	nbr_data.check = 0;
	nbr_data.base = base;
	ft_nbr_base(nbr, &nbr_data);
	nbr_data.check = 1;
	nbr_data.nbr_str = malloc(nbr_data.len);
	ft_nbr_base(nbr, &nbr_data);
	return_str = ft_strdup(nbr_data.nbr_str);
	free(nbr_data.nbr_str);
	if (nbr == -1 && base == 16)
	{
		free(return_str);
		return_str = ft_strdup("ffffffff");
	}
	return (return_str);
}

void	ft_nbr_base(long long nbr, t_nbr_data *nbr_data)
{
	char	*base;
	// unsigned long long	nbr2;
	base = "0123456789abcdef";
	if (nbr < 0)
		nbr *= -1;
	if (nbr > (long long) nbr_data->base - 1)
	{
		ft_nbr_base(nbr / (long long)nbr_data->base, nbr_data);
		ft_nbr_base(nbr % (long long)nbr_data->base, nbr_data);
	}
	else
	{
		nbr += '0';
		if (nbr > '9')
			nbr = base[nbr - '0'];
		if (nbr_data->check == 0)
			nbr_data->len++;
		else if (nbr_data->check == 1)
		{
			nbr_data->nbr_str[nbr_data->i] = nbr;
			nbr_data->i++;
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
