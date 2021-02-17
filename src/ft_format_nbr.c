/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:26:32 by iguidado          #+#    #+#             */
/*   Updated: 2020/04/09 16:26:34 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_i(int nbr, t_format *fmt)
{
	int count;
	int pref;

	count = 0;
	pref = 0;
	fmt->preci = ft_ruler_i(nbr, fmt->preci);
	count += ft_padding_left(*fmt);
	if (nbr || fmt->preci)
	{
		if (nbr < 0)
		{
			count += write(1, "-", 1);
			pref++;
		}
		count += ft_padding_0(*fmt);
		count += ft_putf_i(nbr, fmt->preci - pref);
	}
	count += ft_padding_right(*fmt);
	return (count);
}

int	ft_format_u(unsigned int nbr, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = ft_ruler_u(nbr, fmt->preci);
	count += ft_padding_left(*fmt);
	if (nbr || fmt->preci)
	{
		count += ft_padding_0(*fmt);
		count += ft_putf_u(nbr, fmt->preci);
	}
	count += ft_padding_right(*fmt);
	return (count);
}

int	ft_format_x(unsigned int nbr, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = ft_ruler_x(nbr, fmt->preci);
	count += ft_padding_left(*fmt);
	if (nbr || fmt->preci)
	{
		count += ft_padding_0(*fmt);
		if (fmt->type == 'x')
			count += ft_putf_x(nbr, fmt->preci);
		else
			count += ft_putf_hex(nbr, fmt->preci);
	}
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
