/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:48:07 by iguidado          #+#    #+#             */
/*   Updated: 2020/05/11 04:15:42 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_perc(t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = 1;
	count += ftpf_padding_left(*fmt);
	count += ftpf_padding_0(*fmt);
	count = write(1, "%", 1);
	count += ftpf_padding_right(*fmt);
	return (count);
}

int	ftpf_post_str(const char **str)
{
	int i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	write(1, (*str), i);
	*str = &(*str)[i];
	return (i);
}

int	ftpf_post_format(const char **str, va_list arg)
{
	t_format fmt;

	fmt = ftpf_get_format(str, arg);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	int			ret;
	va_list		ap;

	if (!str)
		return (-1);
	count = 0;
	va_start(ap, str);
	while (*str)
	{
		count += ftpf_post_str(&str);
		if (*str == '%')
		{
			str++;
			ret = ftpf_process_type(&str, ap);
			count += ret;
			if (ret == -1)
				count = -1;
		}
	}
	va_end(ap);
	return (count);
}
