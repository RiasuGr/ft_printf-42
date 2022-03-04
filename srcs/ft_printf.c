/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:29:56 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:29:59 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_converters(int num)
{
	char	*(*f[9])(va_list, t_params *, int *);

	(f[0]) = &ft_c_char;
	(f[1]) = &ft_c_str;
	(f[2]) = &ft_c_ptr;
	(f[3]) = &ft_c_digit;
	(f[4]) = &ft_c_digit;
	(f[5]) = &ft_c_unsigned;
	(f[6]) = &ft_c_hexa;
	(f[7]) = &ft_c_hexa_cap;
	(f[8]) = &ft_c_noarg;
	return ((*f[num]));
}

static char	*ft_apply_conversion(va_list ap, t_params *params, int *len)
{
	char	*str;
	char	*convs;
	int		conv_num;
	char	*(*converter)(va_list, t_params *, int *);

	convs = CONVERSIONS;
	conv_num = ft_strchr(convs, params->s.type) - convs;
	if (conv_num < 0)
		return (NULL);
	converter = ft_converters(conv_num);
	str = converter(ap, params, len);
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_apply_flags(char *str, t_params *params, int *len)
{
	char	*new;

	new = str;
	if (params->s.precision)
	{
		new = ft_f_precision(new, params, len);
		if (!new)
			return (NULL);
	}
	if (params->s.min_width)
	{
		new = ft_f_minimum_width(new, params, len);
		if (!new)
			return (NULL);
	}
	return (new);
}

static int	ft_apply_conv_and_flags(va_list ap, t_params **params, int *count)
{
	char	*str;
	int		len;

	len = 0;
	(*params)->s.count = *count;
	str = ft_apply_conversion(ap, *params, &len);
	if (!str)
		return (ft_free_params(params, ERROR));
	str = ft_apply_flags(str, *params, &len);
	if (!str)
		return (ft_free_params(params, ERROR));
	ft_memprint_fd(str, len, 1, count);
	free(str);
	ft_free_params(params, OK);
	return (OK);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_params	*params;
	int			count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			params = NULL;
			if (ft_init_params(ap, &format, &params) == ERROR)
				break ;
			else if (ft_apply_conv_and_flags(ap, &params, &count) == ERROR)
				++format;
		}
		else
		{
			ft_putchar_count_fd(*format, 1, &count);
			++format;
		}
	}
	va_end(ap);
	return (count);
}
