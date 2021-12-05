/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:00 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/26 02:31:02 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soo_loong.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen_bis(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write (1, "2", 1);
			nb = 147483648;
		}
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}
