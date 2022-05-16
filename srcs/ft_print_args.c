/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/16 17:57:45 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test(t_args *lstargs)
{
	printf("\nType: (%c)\nPrefix (%c)\nPre_Type(%c)\nPre_size (%d)\nValid (%d)\n",
		lstargs->type,
		lstargs->prefix,
		lstargs->precision_type,
		lstargs->precision_size,
		lstargs->valid_arg);
	ft_reset_list(lstargs);
}

int	get_i_int(t_args *lstargs, int i, int arg_len, int p_size)
{
	if ((lstargs->type == 'i' || lstargs->type == 'd' )
		&& (lstargs->precision_type == '.' && lstargs->first_params.nbr > 0))
	{
		i = lstargs->first_params.nbr - p_size;
		if (lstargs->printable_arg[0] == '-'
			&& (lstargs->first_params.sign == '-' && arg_len
				> p_size))
		{
			i = arg_len - p_size + 1;
			return (i);
		}
		if (lstargs->printable_arg[0] == '-' && arg_len > p_size)
			i--;
		if (lstargs->first_params.sign == '-'
			&& arg_len
			< p_size && lstargs->printable_arg[0] != '-')
			i++;
		if (p_size
			> arg_len
			&& lstargs->first_params.sign != '-')
			i++;
		if (lstargs->first_params.sign == '-')
			i--;
	}
	return (i);
}

static int	get_i_double(t_args *lstargs, int i)
{
	int	arg_len;

	arg_len = ft_strlen(lstargs->printable_arg);
	if (lstargs->first_params.nbr > arg_len
		&& lstargs->precision_size < arg_len)
		i++;
	else if (arg_len > lstargs->precision_size
		&& lstargs->first_params.sign != '-')
		i++;
	else if (lstargs->precision_size - arg_len == 1)
		i++;
	else if (lstargs->first_params.nbr > arg_len
		&& lstargs->precision_size > arg_len)
		i += lstargs->first_params.nbr - arg_len;
	if (lstargs->first_params.nbr > arg_len
		&& lstargs->precision_size < arg_len)
		i--;
	return (i);
}

static int	ft_get_i(t_args *lstargs)
{
	int	i;
	int	j;
	int	arg_len;
	int	pre_size;

	pre_size = lstargs->precision_size;
	arg_len = ft_strlen(lstargs->printable_arg);
	j = arg_len - pre_size;
	i = lstargs->first_params.nbr
		- arg_len;
	if (pre_size > 0)
		i += j;
	if (lstargs->first_params.nbr > arg_len
		&& lstargs->first_params.sign != '-')
		i++;
	if (lstargs->type == 'c' && lstargs->printable_arg[0] == 0)
		i--;
	if (lstargs->first_params.nbr > 0 && pre_size > 0)
	{
		i = get_i_double(lstargs, i);
		i = get_i_int(lstargs, i, arg_len, pre_size);
	}
	return (i);
}

void	ft_width_print(t_args *lstargs)
{
	int	i;

	i = ft_get_i(lstargs);
	//printf("I = (%d) J = (%d) PRE SIZE (%d)\n", i, j, lstargs->precision_size);
	if (lstargs->first_params.sign != '-')
	{
		while (i-- > 0 && i)
			ft_putchar(' ', lstargs);
		ft_final_print(lstargs);
	}
	else if (lstargs->first_params.sign == '-')
	{
		ft_final_print(lstargs);
		while (i-- > 0)
			ft_putchar(' ', lstargs);
	}
}

int	ft_print_argument(t_args *lstargs)
{
	//ft_call(test, lstargs);
	ft_call(ft_getfnc(lstargs), lstargs);
	//printf("TEST\n");
	ft_print_prefix(lstargs);

	if (lstargs->first_params.nbr)
		ft_width_print(lstargs);
	else
		ft_final_print(lstargs);

	ft_reset_list(lstargs);
	return (0);
}

