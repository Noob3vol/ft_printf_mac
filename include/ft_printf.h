/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:57:50 by iguidado          #+#    #+#             */
/*   Updated: 2021/01/11 13:29:35 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define BASE10		"0123456789"
# define BASE16_LOW	"0123456789abcdef"
# define BASE16_UPP	"0123456789ABCDEF"
# define FLAGS		"0-"
# define FLAG_ALL	3
# define FLAG_MIN	2
# define FLAG_0		1
# define TYPES		"cspdiuxX%"

typedef struct	s_format
{
	char	msk_flag;
	int		field;
	int		preci;
	char	size;
	char	type;
}				t_format;

/*
**	ft_ruler : to mesure datalen
*/

int				ft_ruler_i(int nbr, int preci);
int				ft_ruler_u(unsigned int nbr, int preci);
int				ft_ruler_x(unsigned int nbr, int preci);
int				ft_ruler_p(unsigned long nbr, int preci);
int				ft_ruler_s(char *str, int preci);

/*
**	ft_putf_* : to print the actual value without surrounding
*/

int				ft_putf_i(int nbr, int len);
int				ft_putf_u(unsigned int nbr, int len);
int				ft_putf_x(unsigned int nbr, int len);
int				ft_putf_hex(unsigned int nbr, int len);
int				ft_putf_p(unsigned long nbr, int len);
int				ft_putf_s(char *str, int len);

/*
**	ft_* : functions printing formatted value
*/

int				ft_format_i(int nbr, t_format *fmt);
int				ft_format_u(unsigned int nbr, t_format *fmt);
int				ft_format_p(unsigned long nbr, t_format *fmt);
int				ft_format_x(unsigned int nbr, t_format *fmt);
int				ft_format_s(char *str, t_format *fmt);
int				ft_format_c(unsigned char nbr, t_format *fmt);
int				ft_format_perc(t_format *fmt);

/*
**	ft_prefix : to add prefix
*/

int				ft_padding_left(t_format fmt);
int				ft_padding_0(t_format fmt);
int				ft_padding_right(t_format fmt);
char			ft_get_flags(const char **str);
int				ft_get_fields(const char **str, va_list arg);
t_format		ft_get_format(const char **str, va_list arg);

/*
**	analyse type to get good function
*/

int				ft_process_type(const char **str, va_list ap);

/*
**	Arch function
*/

int				ft_post_str(const char **str);
int				ft_printf(const char *str, ...);

/*
**	ft_utils : nice to have
*/

char			ft_is_flag(char c);
char			ft_is_mask(char *str);

#endif
