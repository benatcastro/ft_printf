/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:48:19 by becastro          #+#    #+#             */
/*   Updated: 2022/05/02 08:57:29 by bena             ###   ########.fr       */
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
	void			*type;
	void			*sign;
	struct t_args	*next;
}	t_args;

int		is_in_types(char s, const char *types);
int		ft_is_arg(const char *s);
void	ft_putchar(unsigned char c);
void	ft_putstr(const char *s);
int		ft_printf(char *str, ...);
#endif //
