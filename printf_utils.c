/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:36:04 by gojeda            #+#    #+#             */
/*   Updated: 2025/04/24 15:36:05 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_count_digits(int num)
{
	long	n;
	int		count;

	n = num;
	count = 0;
	if (n <= 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (num >= 10)
		count += ft_putunsigned(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr);
	return (count);
}
