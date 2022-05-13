/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:47:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/13 13:51:41 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_s_null_case(t_args *lstargs)
{
	char	*aux;
	int		i;

	i = 0;
	//printf("TETAS\n");
	while (is_in_types(lstargs->arg[i]))
		i++;
	aux = ft_substr(lstargs->arg, 0, i);
	lstargs->null_len = ft_atoi(aux);
	lstargs->null_case = 1;
	free(aux);
}

char	*ft_itoa_base(unsigned long long nbr, int base)
{
	t_nbr_data	nbr_data;
	char		*return_str;

	// nbr_data = malloc(sizeof(nbr_data));

	nbr_data.i = 0;
	nbr_data.check = 0;
	nbr_data.base = base;
	ft_nbr_base(nbr, &nbr_data);
	nbr_data.nbr_str = ft_calloc(nbr_data.len + 1, 1);
	nbr_data.check = 1;
	ft_nbr_base(nbr, &nbr_data);
	return_str = ft_strdup(nbr_data.nbr_str);
	free(nbr_data.nbr_str);
	return (return_str);
}

void	ft_nbr_base(unsigned long long nbr, t_nbr_data *nbr_data)
{
	char	*base;
	base = "0123456789abcdef";
	// if (nbr < 0)
	// 	nbr *= -1;
	//printf("NBR: %lld\n", nbr);
	if ((nbr > (unsigned long long) nbr_data->base - 1))
	{
		ft_nbr_base(nbr / (unsigned long long)nbr_data->base, nbr_data);
		ft_nbr_base(nbr % (unsigned long long)nbr_data->base, nbr_data);
		//printf("NBR TEST (%llu)\n", nbr);
	}
	else
	{
		nbr += '0';
		if (nbr > '9')
			nbr = base[nbr - '0'];
		if (nbr_data->check == 0)
		{
			nbr_data->len++;
			//printf("test %d nbr %llu Check: (%d)\n", nbr_data->len, nbr, nbr_data->check);
		}
		else if (nbr_data->check == 1)
		{
			nbr_data->nbr_str[nbr_data->i] = nbr;
			nbr_data->i++;
		}
	}
}

void	ft_reset_list(t_args *lstargs)
{
	lstargs->type = 0;
	lstargs->prefix = 0;
	lstargs->precision_type = 0;
	lstargs->precision_size = 0;
	lstargs->valid_arg = 0;
	lstargs->write_pre = 0;
	lstargs->null_case = 0;
	free(lstargs->arg);
	free(lstargs->printable_arg);
}
