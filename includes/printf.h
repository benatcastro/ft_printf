/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:48:19 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 02:57:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct t_args
{
	char			type;
	char			prefix;
	va_list			argument;
	char			*test;
	struct t_args	*next;
}	t_args;

//prints
void	s(t_args *lstargs);
void	d(t_args *lstargs);
//other fncs
void	*ft_getfnc(char c);
void	ft_call(void (*f)(t_args), t_args *lstargs);
int		is_in_flags(char c);
int		ft_print_argument(t_args *lstargs);
t_args	*ft_getflags(char *arg, t_args *lstargs);
int		is_in_types(char s);
int		ft_is_arg(const char *s);
void	ft_putchar(unsigned char c);
void	ft_putstr(const char *s);
int		ft_printf(char *str, ...);
#endif //
