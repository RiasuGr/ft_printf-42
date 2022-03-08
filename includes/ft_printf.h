/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:30:28 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/08 11:02:36 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define ERROR -1
# define OK	0
# define CONVERSIONS "cspdiuxX%"
# define FLAGS ".m0-+ #"
# define PSIZE 10

typedef union u_params
{
	struct s_params {
		int		precision;
		int		min_width;
		int		zero;
		int		negative;
		int		positive;
		int		space;
		int		hash;
		int		count;
		int		precision_val;
		int		type;
	}			s;
	int		a_params[PSIZE];
}			t_params;

int		ft_printf(const char *format, ...);
void	ft_putchar_count_fd(char c, int fd, int *count);
void	ft_memprint_fd(char *str, int len, int fd, int *count);
char	*ft_c_char(va_list ap, t_params *params, int *len);
char	*ft_c_str(va_list ap, t_params *params, int *len);
char	*ft_c_ptr(va_list ap, t_params *params, int *len);
char	*ft_c_digit(va_list ap, t_params *params, int *len);
char	*ft_c_integer(va_list ap, t_params *params, int *len);
char	*ft_c_unsigned(va_list ap, t_params *params, int *len);
char	*ft_c_hexa(va_list ap, t_params *params, int *len);
char	*ft_c_hexa_cap(va_list ap, t_params *params, int *len);
char	*ft_c_noarg(va_list ap, t_params *params, int *len);
char	*ft_c_n(va_list ap, t_params *params, int *len);
char	*ft_f_negative(char *str, t_params *params, int *len);
char	*ft_f_minimum_width(char *str, t_params *params, int *len);
char	*ft_f_zero(char *str, t_params *params, int *len);
char	*ft_f_precision(char *str, t_params *params, int *len);
int		ft_init_params(va_list ap, const char **format, t_params **params);
int		ft_free_params(t_params **params, int ret);

#endif