/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:56:34 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 18:56:45 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include "color.h"
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# define BUFF_PRINTF 128
# define ERROR	ftprintf_error
# define EXPONENT lst->exponent
# define HASH lst->hash
# define SPACE	lst->space
# define ZERO lst->zero
# define SIGN lst->sign
# define LOCAL lst->local
# define FIELD lst->field
# define POINT lst->point
# define STRICT lst->strict
# define MAJOR lst->major
# define PSIGN lst->psign
# define BASE lst->base
# define LENGTH lst->length
# define CONVERT lst->convert

typedef struct	s_printf
{
	va_list			va_lst;
	va_list			va_copy;
	int				buff_count;
	UCHAR			buff[BUFF_PRINTF];
	int				count;
	UCHAR			*str;
	ULONG			ul_numb;
	ULONG			ful_numb;
	long double		fl_numb;
	int				exponent;
	MINT			hash;
	MINT			space;
	MINT			zero;
	MINT			sign;
	MINT			local;
	int				field;
	MINT			point;
	int				strict;
	MINT			major;
	char			*psign;
	MUINT			base;
	size_t			length;
	char			convert;
}				t_pf;
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_sprintf(UCHAR **dest, const char *format, ...);
void			recast_char(t_pf *lst);
void			recast_int(t_pf *lst);
void			recast_string(t_pf *lst);
void			recast_double(t_pf *lst, ULONG *numb, int i);
void			recast_other(t_pf *lst);
int				recast_tabstring(t_pf *lst);
int				recast_color(t_pf *lst, char *str);
void			recast_nlen(t_pf *lst);
t_pf			*lst_init(void);
int				lst_putoption(t_pf *lst, char *str, int index);
void			lst_zero(t_pf *lst);
void			lst_putdollar(t_pf *lst, int len);
void			lst_putint(t_pf *lst);
void			lst_putdouble(t_pf *lst);
void			ftprintf_error(t_pf *lst, char *str, size_t index);
int				ulen_base(ULONG numb, size_t base);
size_t			len_pstrn(UCHAR *str, size_t len, size_t index);
void			convert_buff(t_pf *lst, void *tmp, size_t len);
void			put_buff(t_pf *lst, void *tmp, size_t len, size_t index);
void			put_itoa(t_pf *lst, ULONG n);
void			put_prefix(t_pf *lst, int len, int numb, int point);
void			put_sign(t_pf *lst);
void			debug(t_pf *lst);

#endif
