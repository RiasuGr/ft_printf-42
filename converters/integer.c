/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:02 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:32:03 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_add_c_front(char *str, char c)
{
	char	*res;

	res = (char *)malloc(sizeof(*res) * (ft_strlen(str) + 2));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	res[0] = c;
	ft_strlcpy(res + 1, str, ft_strlen(str) + 1);
	free(str);
	return (res);
}

char	*ft_c_integer(va_list ap, t_params *params, int *len)
{
	char	*res;

	if (!params)
		return (NULL);
	res = ft_itoa(va_arg(ap, int));
	if (!res)
		return (NULL);
	if ((params->s.positive || params->s.space) && res[0] != '-')
	{
		if (params->s.positive)
			res = ft_add_c_front(res, '+');
		else if (params->s.space)
			res = ft_add_c_front(res, ' ');
		if (!res)
			return (NULL);
	}
	*len = ft_strlen(res);
	return (res);
}
