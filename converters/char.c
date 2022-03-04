/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:13 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:32:14 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_c_char(va_list ap, t_params *params, int *len)
{
	char	*res;
	char	c;

	if (!params)
		return (NULL);
	res = (char *)ft_calloc(2, 1);
	if (!res)
		return (NULL);
	c = va_arg(ap, int);
	res[0] = c;
	res[1] = 0;
	*len = 1;
	return (res);
}
