/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:47:50 by bena              #+#    #+#             */
/*   Updated: 2022/05/10 04:14:16 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"




char	*c_to_str(char c)
{
	char	*s;

	s = malloc(2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}
void	ft_nbr_to_hexa(long long nbr, t_args *lstargs)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	size_base = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', lstargs);
	}
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i)
		ft_putchar(base[nbr_final[i]], lstargs);
}

char	*ft_putnbr_base(int nbr, t_args *lstargs)
{
	//int		size_base;
	//int		nbr_final[100];
	char	*str;
	int		i;
	char	*base;
	str = malloc(100);
	base = "0123456789abcdef";
	i = 0;
	//size_base = 16;
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-', lstargs);
		}
		while (nbr)
		{
			ft_strlcat(str, c_to_str(base[nbr % 16]), 1);
			//nbr_final[i] = nbr % 16;
			nbr /= 16;
			//printf("TEST:(%d)(%d)", nbr, nbr_final[i]);
			i++;
		}
		return (str);
		// while (--i >= 0)
		// 	ft_putchar(base[nbr_final[i]], lstargs);
}

