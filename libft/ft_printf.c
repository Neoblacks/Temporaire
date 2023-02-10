/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:20:24 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/13 18:57:42 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_printf_args(int fd, const char *format, int i, va_list ap)
{
	if (format[i + 1] == '%')
		return (ft_putcharacter(fd, '%'));
	else if (format[i + 1] == 'c')
		return (ft_putcharacter(fd, va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstring(fd, va_arg(ap, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_putnbr_i(fd, va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_putnbr_u(fd, va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
	{
		if (format[i + 1] == 'X')
			return (ft_put_hex(fd, va_arg(ap, unsigned int), \
			"0123456789ABCDEF"));
		else
			return (ft_put_hex(fd, va_arg(ap, unsigned int), \
			"0123456789abcdef"));
	}
	else if (format[i + 1] == 'p')
		return (ft_put_pointer(fd, va_arg(ap, void *), \
		"0123456789abcdef"));
	else
		return (ft_putcharacter(fd, '%'), \
		ft_putcharacter(fd, format[i + 1]), 2);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ret += ft_printf_args(fd, format, i, ap);
			++i;
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				break ;
			ret += ft_putcharacter(fd, format[i]);
		}
		i++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
