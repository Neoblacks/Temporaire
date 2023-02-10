/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:35:05 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 15:59:14 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

int		ft_dprintf(int fd, const char *format, ...);
int		ft_putcharacter(int fd, char c);
int		ft_putstring(int fd, char *str);
int		ft_putnbr_i(int fd, int nbr);
int		ft_putnbr_u(int fd, unsigned int nbr);
int		ft_printf_args(int fd, const char *format, int i, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_hexabase(unsigned long nbr);
char	*ft_hextostr(unsigned long nbr, char *base);
int		ft_put_pointer(int fd, void *nbr, char *base);
int		ft_put_hex(int fd, unsigned int nbr, char *base);

#endif
