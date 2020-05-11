/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_process_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:33:57 by iguidado          #+#    #+#             */
/*   Updated: 2020/05/11 04:49:32 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_c(unsigned char c, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = 1;
	count += ftpf_padding_left(*fmt);
	count += write(1, &c, 1);
	count += ftpf_padding_right(*fmt);
	return (count);
}

int	ftpf_putf_s(char *str, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!str && len == 6)
		count += write(1, "(null)", len);
	else if (str)
		count += write(1, str, len);
	return (count);
}

int	ftpf_s(char *str, t_format *fmt)
{
	int		count;

	count = 0;
	fmt->preci = ftpf_ruler_s(str, fmt->preci);
	count += ftpf_padding_left(*fmt);
	count += ftpf_putf_s(str, fmt->preci);
	count += ftpf_padding_right(*fmt);
	return (count);
}

int	ftpf_p(unsigned long nbr, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = ftpf_ruler_p(nbr, fmt->preci);
	count += ftpf_padding_left(*fmt);
	count += write(1, "0x", 2);
	count += ftpf_padding_0(*fmt);
	if (nbr || fmt->preci > 2)
		count += ftpf_putf_p(nbr, fmt->preci - 2);
	count += ftpf_padding_right(*fmt);
	return (count);
}

int	ftpf_process_type(const char **str, va_list ap)
{
	t_format	fmt;
	int			count;

	fmt = ftpf_get_format(str, ap);
	count = 0;
	if (!(fmt.type = **str))
		return (-1);
	if (fmt.type == '%')
		count = ftpf_perc(&fmt);
	else if (fmt.type == 'c')
		count = ftpf_c((unsigned char)va_arg(ap, int), &fmt);
	else if (fmt.type == 's')
		count = ftpf_s(va_arg(ap, char *), &fmt);
	else if (fmt.type == 'i' || fmt.type == 'd')
		count = ftpf_i(va_arg(ap, int), &fmt);
	else if (fmt.type == 'p')
		count = ftpf_p(va_arg(ap, unsigned long), &fmt);
	else if (fmt.type == 'u')
		count = ftpf_u(va_arg(ap, unsigned int), &fmt);
	else if (fmt.type == 'x' || fmt.type == 'X')
		count = ftpf_x(va_arg(ap, unsigned int), &fmt);
	else
		return (0);
	(*str)++;
	return (count);
}
