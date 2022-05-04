/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:39:43 by becastro          #+#    #+#             */
/*   Updated: 2022/05/04 15:21:56by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"


int	main(void)
{
	int	i;

	printf("my printf\n");
	i = ft_printf("hello, %+d\n", 123);
	printf("my return: %d", i);
	i = printf("hello, %06d\n", 123);
	printf("Og return: %d", i);
}
