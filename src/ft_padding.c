/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:24:20 by iguidado          #+#    #+#             */
/*   Updated: 2021/02/15 23:25:45 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding_left(t_format fmt)
{
	int count;

	if (fmt.msk_flag & FLAG_ALL)
		return (0);
	count = 0;
	while (fmt.field > fmt.preci)
	{
		count += write(1, " ", 1);
		fmt.field--;
	}
	return (count);
}

int	ft_padding_0(t_format fmt)
{
	int count;

	if ((fmt.msk_flag & FLAG_ALL) != FLAG_MIN)
		return (0);
	count = 0;
	while (fmt.field > fmt.preci)
	{
		count += write(1, "0", 1);
		fmt.field--;
	}
	return (count);
}

int	ft_padding_right(t_format fmt)
{
	int count;

	if (!(fmt.msk_flag & FLAG_MIN))
		return (0);
	count = 0;
	while (fmt.field > fmt.preci)
	{
		count += write(1, " ", 1);
		fmt.field--;
	}
	return (count);
}
