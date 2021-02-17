/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:48:07 by iguidado          #+#    #+#             */
/*   Updated: 2021/02/17 16:35:17 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_post_str(const char **str)
{
	int i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	write(1, (*str), i);
	*str = &(*str)[i];
	return (i);
}

/*
**	int	ft_post_format(const char **str, va_list arg)
**	{
**		t_format fmt;
**
**		fmt = ft_get_format(str, arg);
**		return (0);
**	}
*/

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
		count += ft_post_str(&str);
		if (*str == '%')
		{
			str++;
			ret = ft_process_type(&str, ap);
			count += ret;
			if (ret == -1)
				count = -1;
		}
	}
	va_end(ap);
	return (count);
}
