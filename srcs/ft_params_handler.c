/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:30:21 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:30:22 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_free_params(t_params **params, int ret)
{
	free(*params);
	*params = NULL;
	return (ret);
}

void	ft_zero_param(t_params **params, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		(*params)->a_params[i] = 0;
}

int	ft_get_type(t_params **params, const char **format)
{
	if (**format)
	{
		(*params)->s.type = **format;
		++(*format);
	}
	else
		return (ERROR);
	return (OK);
}

int	ft_val(va_list ap, const char **format)
{
	int	result;

	result = 0;
	if (!ft_isdigit(**format) && **format != '*')
		++(*format);
	if (**format == '*')
	{
		++(*format);
		return (va_arg(ap, int));
	}
	if (!ft_isdigit(**format))
		return (0);
	while (ft_isdigit(**format))
	{
		result = (result * 10) + (**format - 48);
		++(*format);
	}
	return (result);
}

int	ft_init_params(va_list ap, const char **format, t_params **params)
{
	char	*flags;

	flags = FLAGS;
	*params = (t_params *)malloc(sizeof(**params));
	if (!(*params))
		return (ERROR);
	ft_zero_param(params, PSIZE);
	while (**format && (!ft_strchr(CONVERSIONS, **format)))
	{
		if (ft_strchr(flags, **format) && **format != 'm')
		{
			++(*params)->a_params[ft_strchr(flags, **format) - flags];
			if (**format == '.')
				(*params)->s.precision_val = ft_val(ap, format);
			else
				++(*format);
		}
		else if (ft_isdigit(**format) || **format == '*')
			(*params)->s.min_width = ft_val(ap, format);
		else
			return (ft_free_params(params, ERROR));
	}
	if (ft_get_type(params, format) == ERROR)
		return (ft_free_params(params, ERROR));
	return (OK);
}
