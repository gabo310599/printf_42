/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:52:11 by gojeda            #+#    #+#             */
/*   Updated: 2025/04/21 13:52:13 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
/****************************************************************************/
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
void	ft_putnbr_base(int nb, char *base);
int		ft_count_digits(int num);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long n);
int		ft_putptr(void *ptr);
int		ft_count_hex_digits(unsigned int n);
int		ft_validate_base_errors(char *base, int len);
void	ft_putnbr_base_unsigned(unsigned int num, char *base);
int		ft_calculate_base_len(char *base);
/****************************************************************************/
#endif
