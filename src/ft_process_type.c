/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:33:57 by iguidado          #+#    #+#             */
/*   Updated: 2021/02/15 13:43:12 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_c(unsigned char c, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = 1;
	count += ft_padding_left(*fmt);
	count += write(1, &c, 1);
	count += ft_padding_right(*fmt);
	return (count);
}

int	ft_putf_s(char *str, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!str)
	{
		len = len >= 6 ? 6 : len;
		count += write(1, "(null)", len);
	}
	else
		count += write(1, str, len);
	return (count);
}

int	ft_format_s(char *str, t_format *fmt)
{
	int		count;

	count = 0;
	fmt->preci = ft_ruler_s(str, fmt->preci);
	count += ft_padding_left(*fmt);
	count += ft_putf_s(str, fmt->preci);
	count += ft_padding_right(*fmt);
	return (count);
}

int	ft_format_p(unsigned long nbr, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = ft_ruler_p(nbr, fmt->preci);
	count += ft_padding_left(*fmt);
	count += write(1, "0x", 2);
	count += ft_padding_0(*fmt);
	if (nbr || fmt->preci > 2)
		count += ft_putf_p(nbr, fmt->preci - 2);
	count += ft_padding_right(*fmt);
	return (count);
}

int	ft_process_type(const char **str, va_list ap)
{
	t_format	fmt;
	int			count;

	fmt = ft_get_format(str, ap);
	count = 0;
	if (!(fmt.type = **str))
		return (-1);
	if (fmt.type == '%')
		count = ft_format_perc(&fmt);
	else if (fmt.type == 'c')
		count = ft_format_c((unsigned char)va_arg(ap, int), &fmt);
	else if (fmt.type == 's')
		count = ft_format_s(va_arg(ap, char *), &fmt);
	else if (fmt.type == 'i' || fmt.type == 'd')
		count = ft_format_i(va_arg(ap, int), &fmt);
	else if (fmt.type == 'p')
		count = ft_format_p(va_arg(ap, unsigned long), &fmt);
	else if (fmt.type == 'u')
		count = ft_format_u(va_arg(ap, unsigned int), &fmt);
	else if (fmt.type == 'x' || fmt.type == 'X')
		count = ft_format_x(va_arg(ap, unsigned int), &fmt);
	else
		return (0);
	(*str)++;
	return (count);
}
