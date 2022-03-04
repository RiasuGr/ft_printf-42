/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:31:49 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:31:50 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_nb_len(unsigned int n)
{
	int				len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static char	*ft_itoutoa(int n)
{
	char	*res;
	long	nb;
	int		len;

	nb = (unsigned int)n;
	len = ft_nb_len(nb);
	res = (char *)malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (--len >= 0 && nb != 0)
	{
		res[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

char	*ft_c_unsigned(va_list ap, t_params *params, int *len)
{
	char	*res;

	if (!params)
		return (NULL);
	res = ft_itoutoa(va_arg(ap, int));
	if (!res)
		return (NULL);
	*len = ft_strlen(res);
	return (res);
}
