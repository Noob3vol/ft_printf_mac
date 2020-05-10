/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_putf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:49:55 by iguidado          #+#    #+#             */
/*   Updated: 2020/04/09 16:34:49 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_putf_i(int nbr, int len)
{
	int		count;
	char	c;

	count = 0;
	if (nbr < -9 || nbr > 9 || len > 1)
		count += ftpf_putf_i(nbr / 10, len - 1);
	nbr = nbr % 10;
	nbr = (nbr < 0 ? -nbr : nbr);
	c = nbr + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ftpf_putf_u(unsigned int nbr, int len)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 9 || len > 1)
		count += ftpf_putf_i(nbr / 10, len - 1);
	nbr = nbr % 10;
	c = (char)(nbr + '0');
	count += write(1, &c, 1);
	return (count);
}

int	ftpf_putf_p(unsigned long nbr, int len)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 15 || len > 1)
		count += ftpf_putf_p(nbr / 16, len - 1);
	nbr = nbr % 16;
	if (nbr > 9)
		c = (char)(nbr + 'a' - 10);
	else
		c = (char)(nbr + '0');
	count += write(1, &c, 1);
	return (count);
}

int	ftpf_putf_x(unsigned int nbr, int len)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 15 || len > 1)
		count += ftpf_putf_x(nbr / 16, len - 1);
	nbr = nbr % 16;
	if (nbr > 9)
		c = (char)(nbr + 'a' - 10);
	else
		c = (char)(nbr + '0');
	count += write(1, &c, 1);
	return (count);
}

int	ftpf_putf_hex(unsigned int nbr, int len)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 15 || len > 1)
		count += ftpf_putf_hex(nbr / 16, len - 1);
	nbr = nbr % 16;
	if (nbr > 9)
		c = (char)(nbr + 'A' - 10);
	else
		c = (char)(nbr + '0');
	count += write(1, &c, 1);
	return (count);
}
