/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/06 21:32:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	main(void)
{
	int	i;

	///printf("my printf\n");
	i = ft_printf("my printf, %06d test\n", 123);
	printf("original,%06d test\n", 123);
	//printf("my return: %d", i);
	//i = ft_printf("hello, %s\n", "HOplah sadjkhfg fg kjghfg  kajhdsf gFGH KSAD KajsdhffdgghfkJHAFGDS");
	//i = ft_printf("hello, %d\n", -123);
	//i = ft_printf("hello, %d\n", 123);
	//i = ft_printf("hello, %d\n", 123);
	//i = ft_printf("hello, %d\n", 123);
	//i = printf("hello, %-10dhola\n", 123);
	//printf("Og return: %d", i);
}
