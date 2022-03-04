/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:30:33 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:30:34 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_copytores(char *res, const char *str, int pad, int len)
{
	int	pre;

	pre = 0;
	if (pad)
	{
		if (ft_strchr("-+ ", str[0]))
		{
			pre = 1;
			res[0] = str[0];
		}
		if (ft_strlen(str) > 1 && ft_strchr("xX", str[1]))
		{
			pre = 2;
			res[0] = str[0];
			res[1] = str[1];
		}
		res = ft_memset(res + pre, '0', pad);
		res -= pre;
	}
	ft_strlcpy(res + pad + pre, str + pre, len - pad + 1);
	return (res);
}

static char	*ft_copyptores(char *res, const char *str, int pad, int len)
{
	res[0] = '0';
	res[1] = 'x';
	res += 2;
	if (pad)
	{
		res = ft_memset(res, '0', pad);
	}
	ft_strlcpy(res + pad, str + 2, len - pad + 1);
	return (res - 2);
}

static int	ft_getlen(char *str, t_params *params, int len)
{
	int	pre;

	pre = 0;
	if (ft_strchr("%sc", params->s.type))
	{
		if (params->s.precision_val < len && params->s.precision_val >= 0)
			return (params->s.precision_val);
		return (len);
	}
	if ((ft_strchr("xX", params->s.type) && len > 1 \
		&& ft_strchr("xX", str[1])) || (params->s.type == 'p'))
		pre = 2;
	if (ft_strchr("idu", params->s.type) && ft_strchr("-+ ", str[0]))
		pre = 1;
	if (ft_strchr("iduxX", params->s.type) && params->s.precision_val >= 0 \
		&& (((pre == 0 && str[0] == '0') || (pre == 2 && str[2] == '0')) \
		|| (ft_strchr("+- ", str[0]) && str[1] == '0')))
		len = 0;
	if (params->s.type == 'p' && len == 3 && str[2] == '0' \
		&& params->s.precision_val >= 0)
		len = 2;
	if (params->s.precision_val > (len - pre))
		len = params->s.precision_val + pre;
	return (len);
}

static int	ft_getpadding(char *str, t_params *params, int len)
{
	int	padding;
	int	pre;

	padding = 0;
	pre = 0;
	if (ft_strchr("xX", params->s.type) && len > 1 && ft_strchr("xX", str[1]))
		pre = 2;
	else if (ft_strchr("iduxX", params->s.type) && ft_strchr("-+ ", str[0]))
		pre = 1;
	else if (ft_strchr("p", params->s.type))
		pre = 2;
	if (params->s.precision_val > len - pre \
		&& !ft_strchr("%sc", params->s.type))
		padding = params->s.precision_val - len + pre;
	return (padding);
}

char	*ft_f_precision(char *str, t_params *params, int *len)
{
	char	*res;
	int		padding;

	if (params->s.zero && ft_strchr("iduxXp", params->s.type) \
		&& params->s.precision_val >= 0)
		params->s.zero = 0;
	padding = ft_getpadding(str, params, *len);
	*len = ft_getlen(str, params, *len);
	res = (char *)malloc(sizeof(*res) * (*len + 1));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	if (params->s.type != 'p')
		res = ft_copytores(res, str, padding, *len);
	else
		res = ft_copyptores(res, str, padding, *len);
	free(str);
	return (res);
}
