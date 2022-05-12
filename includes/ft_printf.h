/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:48:19 by becastro          #+#    #+#             */
/*   Updated: 2022/05/12 04:03:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct t_args
{
	char		*arg;
	char		*printable_arg;
	int			arg_len;
	char		type;
	char		prefix;
	char		precision_type;
	int			precision_size;
	va_list		variatic_arg;
	int			args_size;
	int			valid_arg;
}	t_args;

typedef struct t_hexa_data
{
	char		*hexa_str;
	int			len;
	int			i;
	int			check;
}	t_hexa_data;

//prints
void	c(t_args *lstargs);
void	s(t_args *lstargs);
void	p(t_args *lstargs);
void	d(t_args *lstargs);
void	x(t_args *lstargs);
void	upper_x(t_args *lstargs);
void	percent(t_args *lstargs);
//conversionsi
char	*ft_itoa_hexa(long long nbr);
void	ft_to_hexa(unsigned long long nbr, t_hexa_data *t_hexa_data);
//precision printers
void	ft_print_precision(t_args *lstargs);
void	ft_print_prefix(t_args *lstargs);
void	ft_print_dot(t_args *lstargs);
void	ft_print_sign(t_args *lstargs);
//other fncs
void	*ft_getfnc(t_args *lstargs);
void	ft_call(void (*f)(t_args*), t_args *lstargs);
int		ft_print_argument(t_args *lstargs);
//getting flags
t_args	*ft_getflags(t_args *lstargs);
int		is_in_types(char s);
int		ft_is_arg(const char *s);
void	ft_get_prefix(t_args *lstargs, char c);
void	ft_get_precision(t_args *lstargs, char *arg);
void	ft_get_precision_size(t_args *lstargs, char *str);
//checking flags
int		is_in_prefix(char c);
int		is_in_precision(char c);
//utils
void	ft_putchar(unsigned char c, t_args *lstargs);
void	ft_putstr(char *s, t_args *lstargs);
char	*ft_trim_arg(char *str);
void	ft_reset_list(t_args *lstargs);
void	test(t_args *lstargs);
int		ft_printf(const char *str, ...);
int		ft_to_positive(int nbr);
#endif //
