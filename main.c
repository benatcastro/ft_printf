/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/16 12:12:52 by becastro         ###   ########.fr       */
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

	int i;

	printf("\n\n!!!!!!TEST1!!!!!\n\n");
	char	*str2 = "%-6s";
	i = printf(str2, "hello");
	printf("i: %d\n", i);
	i = ft_printf(str2, "hello");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST2!!!!!\n\n");
	char	*str3 = "%4d";
	i = printf(str3, 12);
	printf("i: %d\n", i);
	i = ft_printf(str3, 12);
	printf("i: %d\n", i);


	printf("\n\n!!!!!!TEST3!!!!!\n\n");

	char	*str = "%-4c";
	i = 0;
	i = printf(str, 'x');
	printf("i: %d\n", i);
	i = ft_printf(str, 'x');
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST4!!!!!\n\n");

	char	*str5 = " (%-1c) (%-2c) (%-3c)";
	i = 0;
	i = printf(str5, '0', 0, '1');
	printf("i: %d\n", i);
	i = ft_printf(str5, '0', 0, '1');
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST5!!!!!\n\n");

	char	*str4 = "%-7.5s";
	i = printf(str4, "yolo");
	printf("i: %d\n", i);
	i = ft_printf(str4, "yolo");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST6!!!!!\n\n");

	char	*str6 = "%7.7s";
	i = printf(str6, "hello");
	printf("i: %d\n", i);
	i = ft_printf(str6, "hello");
	printf("i: %d\n", i);

	char	*str7 = "%7.7s%7.7s";
	i = printf(str7, "hello", "world");
	printf("i: %d\n", i);
	i = ft_printf(str7, "hello", "world");
	printf("i: %d\n", i);
	 //printf("i: %d\n", i);
	// printf("-----THIS TEST ARE GONNA BE DONE BY PRINTF-----\n");
	// printf("LONG_MAX==%p\nLONG_MIN=%p\nULONG_MAX=%p\n-ULONG_MAX=%p\n", LONG_MAX, LONG_MIN, ULONG_MAX, -ULONG_MAX);
	// printf("!!!!!!!!!!!THIS TEST ARE GONNA BE DONE BY FT_PRINTF!!!!!!!!\n");
	// ft_printf("LONG_MIN=%p\nULONG_MAX=%p\n", LONG_MIN, ULONG_MAX);
	// return 1;
}
