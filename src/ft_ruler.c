/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ruler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:48:28 by iguidado          #+#    #+#             */
/*   Updated: 2020/05/11 04:35:46 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ruler_i(int nbr, int preci)
{
	int nbrlen;
	int neg;

	if (!nbr && !preci)
		return (0);
	nbrlen = 1;
	neg = (nbr < 0 ? 1 : 0);
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		nbrlen++;
	}
	if (preci > nbrlen)
		return (preci + neg);
	return (nbrlen + neg);
}

int	ft_ruler_u(unsigned int nbr, int preci)
{
	int nbrlen;

	if (!nbr && !preci)
		return (0);
	nbrlen = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		nbrlen++;
	}
	if (preci > nbrlen)
		return (preci);
	return (nbrlen);
}

int	ft_ruler_x(unsigned int nbr, int preci)
{
	int nbrlen;

	if (!nbr && !preci)
		return (0);
	nbrlen = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbrlen++;
	}
	if (preci > nbrlen)
		return (preci);
	return (nbrlen);
}

int	ft_ruler_p(unsigned long nbr, int preci)
{
	int nbrlen;

	if (!nbr && !preci)
		return (2);
	nbrlen = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbrlen++;
	}
	if (preci > nbrlen)
		return (preci + 2);
	return (nbrlen + 2);
}

int	ft_ruler_s(char *str, int preci)
{
	if (!str && (preci < 0 || preci >= 6))
		return (6);
	else if (!str)
		return (0);
	if (preci <= -1 || (int)ft_strlen(str) < preci)
		return (ft_strlen(str));
	return (preci);
}
