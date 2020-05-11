#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

#define BASE10		"0123456789"
#define BASE16_LOW	"0123456789abcdef"
#define BASE16_UPP	"0123456789ABCDEF"
#define FLAGS		"0-+#'"
#define FLAG_ALL	3
#define FLAG_MIN	2
#define FLAG_0		1
#define TYPES		"cspdiuxX%"

typedef struct	s_format
{
	char	msk_flag;
	int		field;
	int		preci;
	char	size;
	char	type;
}		t_format;

/*
**	ft_ruler : to mesure datalen
*/


int			ftpf_ruler_i(int nbr, int preci);
int			ftpf_ruler_u(unsigned int nbr, int preci);
int			ftpf_ruler_x(unsigned int nbr, int preci);
int			ftpf_ruler_p(unsigned long nbr, int preci);
int			ftpf_ruler_s(char *str, int preci);



/*
**	ftpf_putf_* : to print the actual value without surrounding
*/


int			ftpf_putf_i(int nbr, int len);
int			ftpf_putf_u(unsigned int nbr, int len);
int			ftpf_putf_x(unsigned int nbr, int len);
int			ftpf_putf_hex(unsigned int nbr, int len);
int			ftpf_putf_p(unsigned long nbr, int len);
int			ftpf_putf_s(char *str, int len);


/*
**	ftpf_* : functions printing formatted value
*/

int			ftpf_i(int nbr, t_format *fmt);
int			ftpf_u(unsigned int nbr, t_format *fmt);
int			ftpf_p(unsigned long nbr, t_format *fmt);
int			ftpf_x(unsigned int nbr, t_format *fmt);
int			ftpf_s(char *str, t_format *fmt);
int			ftpf_c(unsigned char nbr, t_format *fmt);
int			ftpf_perc(t_format *fmt);

/*
**	ft_prefix : to add prefix
*/

int			ftpf_padding_left(t_format fmt);
int			ftpf_padding_0(t_format fmt);
int			ftpf_padding_right(t_format fmt);


/*
**
*/

char		ftpf_get_flags(const char **str);
int			ftpf_get_fields(const char **str, va_list arg);
t_format	ftpf_get_format(const char **str, va_list arg);

/*
**	analyse type to get good function
*/

int			ftpf_process_type(const char **str, va_list ap);

/*
**
*/

int			ft_post_format(const char **str, va_list arg);
int			ft_post_str(const char **str);
int			ft_printf(const char *str, ...);

/*
**	ft_utils : nice to have
*/

char		ftpf_is_flag(char c);
char		ftpf_is_mask(char *str);

#endif
