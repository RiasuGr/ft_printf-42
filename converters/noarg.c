/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noarg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:31:59 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:32:01 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_c_noarg(va_list ap, t_params *params, int *len)
{
	char	*res;

	if (!params)
		return (NULL);
	if (ap)
	{
		res = (char *)malloc(sizeof(*res) * 2);
		if (!res)
			return (NULL);
		res[0] = '%';
		res[1] = 0;
		*len = 1;
		return (res);
	}
	return (NULL);
}
