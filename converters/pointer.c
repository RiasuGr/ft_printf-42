/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:31:56 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:33:39 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_size_in_base(unsigned long nb, int bsize)
{
	int	size;

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

static char	*ft_ultoa_base(unsigned long nb, char *base, int bsize)
{
	int		i;
	int		tab_size;
	char	*number;

	tab_size = ft_size_in_base(nb, bsize);
	number = (char *)malloc(sizeof(*number) * (tab_size + 3));
	if (!number)
		return (NULL);
	number[0] = '0';
	number[1] = 'x';
	if (nb == 0)
		number[2] = '0';
	i = 1;
	while (nb != 0)
	{
		number[tab_size + 2 - i] = base[nb % bsize];
		nb /= bsize;
		++i;
	}
	number[tab_size + 2] = '\0';
	return (number);
}

char	*ft_c_ptr(va_list ap, t_params *params, int *len)
{
	char	*res;

	if (!params)
		return (NULL);
	res = ft_ultoa_base((unsigned long)va_arg(ap, void *), \
	"0123456789abcdef", 16);
	if (!res)
		return (NULL);
	*len = ft_strlen(res);
	return (res);
}
