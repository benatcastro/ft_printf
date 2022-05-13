/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/13 06:39:58 by becastro         ###   ########.fr       */
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
	char	*str = "%5%";
	i = printf(str);
	printf("i: %d\n", i);
	i = ft_printf(str);
	printf("i: %d\n", i);

	// printf("-----THIS TEST ARE GONNA BE DONE BY PRINTF-----\n");
	// printf("LONG_MAX==%p\nLONG_MIN=%p\nULONG_MAX=%p\n-ULONG_MAX=%p\n", LONG_MAX, LONG_MIN, ULONG_MAX, -ULONG_MAX);
	// printf("!!!!!!!!!!!THIS TEST ARE GONNA BE DONE BY FT_PRINTF!!!!!!!!\n");
	// ft_printf("LONG_MIN=%p\nULONG_MAX=%p\n", LONG_MIN, ULONG_MAX);
	// return 1;
}
