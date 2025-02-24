/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:58:53 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/15 20:01:25 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *s)
{
	int		re_value;

	if (!s)
		s = "(null)";
	re_value = 0;
	while (*s)
	{
		re_value += ft_putchr(*s);
		s++;
	}
	return (re_value);
}

static int	ft_putnbr_recursive(int nb)
{
	int	re_value;

	re_value = 0;
	if (nb >= 10)
	{
		re_value += ft_putnbr_recursive(nb / 10);
		re_value += ft_putnbr_recursive(nb % 10);
	}
	else
		re_value += ft_putchr(nb + '0');
	return (re_value);
}

int	ft_putnbr(int nb)
{
	int	re_value;

	re_value = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		re_value += ft_putchr('-');
		nb = -nb;
	}
	re_value += ft_putnbr_recursive(nb);
	return (re_value);
}
