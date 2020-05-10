/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_get_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:44:56 by iguidado          #+#    #+#             */
/*   Updated: 2020/04/10 08:17:44 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ftpf_get_flags(const char **str)
{
	char		msk;

	msk = 0;
	while (**str == '-' || **str == '0')
	{
		if (**str == '0')
			msk |= FLAG_0;
		else
			msk |= FLAG_MIN;
		(*str)++;
	}
	return (msk);
}

int			ftpf_get_fields(const char **str, va_list arg)
{
	int field;

	field = 0;
	if (**str == '*')
	{
		field = va_arg(arg, int);
		(*str)++;
	}
	else
	{
		while (**str >= '0' && **str <= '9')
		{
			field *= 10;
			field += **str - '0';
			(*str)++;
		}
	}
	return (field);
}

t_format	ftpf_get_format(const char **str, va_list arg)
{
	t_format fmt;

	fmt.msk_flag = ftpf_get_flags(str);
	fmt.field = ftpf_get_fields(str, arg);
	if (fmt.field < 0)
	{
		fmt.field = -fmt.field;
		fmt.msk_flag |= FLAG_MIN;
	}
	if (!(**str == '.'))
		fmt.preci = -1;
	else
	{
		(*str)++;
		fmt.preci = ftpf_get_fields(str, arg);
		fmt.msk_flag &= ~FLAG_0;
	}
	return (fmt);
}
