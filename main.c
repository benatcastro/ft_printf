/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/12 04:04:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

// int main(void)
// {
// 	t_args	*lstargs;
// 	lstargs = malloc(sizeof(t_args));
// 	lstargs->arg_len = 0;
// 	int nbr = 1230;
// 	char	*test = ft_itoa_hexa(nbr);
// 	printf("hexa: (%s)\n", test);
// 	printf("OG: (%x)\n", nbr);
// 	free(test);
// 	free(lstargs);
// }

int	main(void)
{
	int		i;
	char	*str;
	void	*p;

	p = &d;
	str = "Hola %%  adios\n";
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
