/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/18 14:55:00 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main1(void)
{
	int i;

		printf("\n\n!!!!!!TEST24!!!!!\n\n");

	char	*str24 = "%5%";
	i = printf(str24);
	printf("i: %d\n", i);
	i = ft_printf(str24);
	printf("i: %d\n", i);
}

int	main(void)
{

	int i;

	printf("i: %d\n", i);
	printf("\n\n!!!!!!TEST1!!!!!\n\n");
	char	*str2 = "%02.2s";
	i = printf(str2, "hello");
	printf("i: %d\n", i);
	i = ft_printf(str2, "hello");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST2!!!!!\n\n");
	char	*str3 = "%%";
	i = printf(str3);
	printf("i: %d\n", i);
	i = ft_printf(str3);
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

	char	*str4 = "%7.5s";
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

	printf("\n\n!!!!!!TEST7!!!!!\n\n");

	char	*str7 = "%7.7s%7.7s";
	i = printf(str7, "hello", "world");
	printf("i: %d\n", i);
	i = ft_printf(str7, "hello", "world");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST8!!!!!\n\n");

	char	*str8 = "%7.3s%7.7s";
	i = printf(str8, "hello", "world");
	printf("i: %d\n", i);
	i = ft_printf(str8, "hello", "world");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST9!!!!!\n\n");
	char	*str9 = "%7.5s";
	i = printf(str9, "bombastic");
	printf("i: %d\n", i);
	i = ft_printf(str9, "bombastic");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST10!!!!!\n\n");

	char	*str10 = "%-7.5s";
	i = printf(str10, "tubular");
	printf("i: %d\n", i);
	i = ft_printf(str10, "tubular");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST11!!!!!\n\n");

	char	*str11 = "%-10.s";
	i = printf(str11, "Hola");
	printf("i: %d\n", i);
	i = ft_printf(str11, "Hola");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST12!!!!!\n\n");

	char	*str12 = "%-10.s";
	i = printf(str12, "");
	printf("i: %d\n", i);
	i = ft_printf(str12, "");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST13!!!!!\n\n");

	char	*str13 = "%8.5i";
	i = printf(str13, 0);
	printf("i: %d\n", i);
	i = ft_printf(str13, 0);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST14!!!!!\n\n");

	char	*str14 = "%-8.5i";
	i = printf(str14, 256);
	printf("i: %d\n", i);
	i = ft_printf(str14, 256);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST15!!!!!\n\n");

	char	*str15 = "%8.3i";
	i = printf(str15, 8431);
	printf("i: %d\n", i);
	i = ft_printf(str15, 8431);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST16!!!!!\n\n");

	char	*str16 = "%8.3i";
	i = printf(str16, 8431);
	printf("i: %d\n", i);
	i = ft_printf(str16, 8431);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST17!!!!!\n\n");

	char	*str17 = "%8.3i";
	i = printf(str17, -8431);
	printf("i: %d\n", i);
	i = ft_printf(str17, -8431);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST18!!!!!\n\n");

	char	*str18 = "%-10.5i";
	i = printf(str18, -256);
	printf("i: %d\n", i);
	i = ft_printf(str18, -256);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST19!!!!!\n\n");

	char	*str19 = "%-8.3i";
	i = printf(str19, 8431);
	printf("i: %d\n", i);
	i = ft_printf(str19, 8431);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST20!!!!!\n\n");

	char	*str20 = "%-8.3i";
	i = printf(str20, -8431);
	printf("i: %d\n", i);
	i = ft_printf(str20, -8431);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST21!!!!!\n\n");

	char	*str21 = "%-3.s";
	i = printf(str21, NULL);
	printf("i: %d\n", i);
	i = ft_printf(str21, NULL);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST22!!!!!\n\n");

	char	*str22 = "%7s%-5s";
	i = printf(str22, "hello", "world");
	printf("i: %d\n", i);
	i = ft_printf(str22, "hello", "world");
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST23!!!!!\n\n");

	char	*str23 = "%10.5i";
	i = printf(str23, -216);
	printf("i: %d\n", i);
	i = ft_printf(str23, -216);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST24!!!!!\n\n");

	char	*str24 = "%-23s";
	i = printf(str24, NULL);
	printf("i: %d\n", i);
	i = ft_printf(str24, NULL);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST25!!!!!\n\n");

	char	*str25 = "%5%";
	i = printf(str25);
	printf("i: %d\n", i);
	i = ft_printf(str25);
	printf("i: %d\n", i);

	printf("\n\n!!!!!!TEST26!!!!!\n\n");

	char	*str26 = "%23s";
	i = printf(str26, NULL);
	printf("i: %d\n", i);
	i = ft_printf(str26, NULL);
	printf("i: %d\n", i);
	// ft_printf("%0d", 1);
	// printf("%0d", 1);
	 //printf("i: %d\n", i);
	// printf("-----THIS TEST ARE GONNA BE DONE BY PRINTF-----\n");
	// printf("LONG_MAX==%p\nLONG_MIN=%p\nULONG_MAX=%p\n-ULONG_MAX=%p\n", LONG_MAX, LONG_MIN, ULONG_MAX, -ULONG_MAX);
	// printf("!!!!!!!!!!!THIS TEST ARE GONNA BE DONE BY FT_PRINTF!!!!!!!!\n");
	// ft_printf("LONG_MIN=%p\nULONG_MAX=%p\n", LONG_MIN, ULONG_MAX);
	// return 1;
}

