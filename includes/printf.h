/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:48:19 by becastro          #+#    #+#             */
/*   Updated: 2022/05/05 19:16:39 by becastro         ###   ########.fr       */
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
	char			precision_type;
	int				precision_size;
	va_list			argument;
	int				args_size;
	struct t_args	*next;
}	t_args;

//prints
void	s(t_args *lstargs);
void	d(t_args *lstargs);
//other fncs
void	*ft_getfnc(t_args *lstargs);
void	ft_call(void (*f)(t_args*), t_args *lstargs);
int		ft_print_argument(t_args *lstargs);
//getting flags
t_args	*ft_getflags(char *arg, t_args *lstargs);
int		is_in_types(char s);
int		ft_is_arg(const char *s);
void	ft_get_prefix(t_args *lstargs, char c);
void	ft_get_precision(t_args *lstargs, char *arg);
//checking flags
int		is_in_prefix(char c);
int		is_in_precision(char c);
//utils
void	ft_putchar(unsigned char c, t_args *lstargs);
void	ft_putstr(const char *s, t_args *lstargs);
int		ft_printf(char *str, ...);
#endif //
