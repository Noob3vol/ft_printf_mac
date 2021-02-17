/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:35:26 by iguidado          #+#    #+#             */
/*   Updated: 2021/02/17 16:35:28 by iguidado         ###   ########.fr       */
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

int	ft_format_s(char *str, t_format *fmt)
{
	int		count;

	count = 0;
	if (!str)
		str = "(null)";
	fmt->preci = ft_ruler_s(str, fmt->preci);
	count += ft_padding_left(*fmt);
	count += write(1, str, fmt->preci);
	count += ft_padding_right(*fmt);
	return (count);
}

int	ft_format_perc(t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = 1;
	count += ft_padding_left(*fmt);
	count += ft_padding_0(*fmt);
	count += write(1, "%", 1);
	count += ft_padding_right(*fmt);
	return (count);
}
