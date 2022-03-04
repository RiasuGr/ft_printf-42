/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabenet <sabenet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:31:45 by sabenet           #+#    #+#             */
/*   Updated: 2022/03/04 15:31:46 by sabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_align_right(char *new, const char *str, int padding, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		new[padding + i] = str[i];
	new[padding + len] = 0;
}

static void	ft_align_zero(char *new, const char *str, int padding, int len)
{
	int	i;
	int	sign;

	sign = 0;
	if (ft_strchr("+- ", str[0]))
	{
		sign = 1;
		new[0] = str[0];
	}
	else if (len > 1 && ft_strchr("Xx", str[1]))
	{
		sign = 2;
		new[0] = str[0];
		new[1] = str[1];
	}
	new = ft_memset(new + sign, '0', padding);
	new -= sign;
	i = -1;
	while (++i < len - sign)
		new[padding + i + sign] = str[i + sign];
	new[padding + len] = 0;
}

static void	ft_align_left(char *new, const char *str, int padding, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		new[i] = str[i];
	new = ft_memset(new + len, ' ', padding);
	new -= len;
	new[padding + len] = 0;
}

static void	ft_alignment(char *new, const char *str, t_params *params, int len)
{
	int	padding;

	padding = ft_strlen(new) - len;
	if (params->s.negative)
		ft_align_left(new, str, padding, len);
	else if (params->s.zero)
		ft_align_zero(new, str, padding, len);
	else
		ft_align_right(new, str, padding, len);
}

char	*ft_f_minimum_width(char *str, t_params *params, int *len)
{
	char	*new;
	int		padding;

	if (params->s.min_width < 0)
	{
		params->s.min_width *= -1;
		++params->s.negative;
	}
	padding = params->s.min_width - *len;
	if (padding < 0)
		padding = 0;
	new = (char *)malloc(sizeof(*new) * (*len + padding + 1));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	new = ft_memset(new, ' ', *len + padding);
	new[*len + padding] = 0;
	ft_alignment(new, str, params, *len);
	free(str);
	*len = *len + padding;
	return (new);
}
