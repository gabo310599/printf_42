/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:57:18 by gojeda            #+#    #+#             */
/*   Updated: 2025/04/25 13:57:21 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	validate(char *base, int len)
{
	int	i;
	int	j;

	if (len <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j]
				|| base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	num;
	int		base_len;

	num = nb;
	base_len = calculate_base_len(base);
	if (validate(base, base_len))
	{
		if (num < 0)
		{
			num = num * -1;
			write(1, "-", 1);
		}
		if (num < base_len)
			write(1, &base[num], 1);
		else
		{
			ft_putnbr_base(num / base_len, base);
			write(1, &base[num % base_len], 1);
		}
	}
}

int	ft_puthex(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_count_hex_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}
