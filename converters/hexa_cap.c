/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:07 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:32:08 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_add_0c_front(char *str, char c)
{
	char	*res;

	res = (char *)malloc(sizeof(*res) * (ft_strlen(str) + 3));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	res[0] = '0';
	res[1] = c;
	ft_strlcpy(res + 2, str, ft_strlen(str) + 1);
	free(str);
	return (res);
}

static int	ft_size_in_base(unsigned int nb, int bsize)
{
	int		size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= bsize;
		size++;
	}
	return (size);
}

static char	*ft_itoa_base(int nbr, char *base, int bsize)
{
	int				i;
	unsigned int	nb;
	int				tab_size;
	char			*number;

	nb = (unsigned int)nbr;
	tab_size = ft_size_in_base(nbr, bsize);
	number = (char *)malloc(sizeof(*number) * (tab_size + 1));
	if (!number)
		return (NULL);
	i = 1;
	if (nb == 0)
		number[0] = '0';
	while (nb != 0)
	{
		number[tab_size - i] = base[nb % bsize];
		nb /= bsize;
		++i;
	}
	number[tab_size] = '\0';
	return (number);
}

char	*ft_c_hexa_cap(va_list ap, t_params *params, int *len)
{
	char	*res;

	if (!params)
		return (NULL);
	res = ft_itoa_base(va_arg(ap, int), "0123456789ABCDEF", 16);
	if (!res)
		return (NULL);
	if (params->s.hash && res[0] != '0')
	{
		res = ft_add_0c_front(res, 'X');
		if (!res)
			return (NULL);
	}
	*len = ft_strlen(res);
	return (res);
}
