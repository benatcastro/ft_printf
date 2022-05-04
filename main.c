/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 03:02:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_testcall(void (*f)(t_args), t_args lstargs)
{
	(*f)(lstargs);
}

int	main(void)
{
	t_args	*lstargs;

	lstargs = malloc(sizeof(lstargs));
	lstargs->test = "hello";
	ft_testcall(&d, *lstargs);
	//ft_printf("hello %      d world %          d\n", 123, 321);
}
