/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/10 04:12:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	char	*s;
	(void)s;
	t_args *lstargs;

	lstargs = malloc(sizeof(t_args));

	printf("test: %s\n", ft_putnbr_base(123, lstargs));
	printf("\nOG: (%x)\n", 123);
}


int	main2(void)
{
	int		i;
	char	*str;

	str = "my printf, %+02d test\n";

	i = ft_printf(str, 123);
	printf("i = %d\n", i);
	i = printf(str, 123);
	printf("i = %d \n", i);
	//printf("my return: %d", i);
	//i = ft_printf("hello, %s\n", "HOplah sadjkhfg fg kjghfg  kajhdsf gFGH KSAD KajsdhffdgghfkJHAFGDS");
	//i = ft_printf("hello, %d\n", -123);
	//i = ft_printf("hello, %d\n", 123);
	//i = ft_printf("hello, %d\n", 123);
	//i = ft_printf("hello, %d\n", 123);
	//i = printf("hello, %-10dhola\n", 123);
	//printf("Og return: %d", i);
}
