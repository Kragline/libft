/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:45:36 by armarake          #+#    #+#             */
/*   Updated: 2024/12/22 20:45:36 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*str_rev(char *str)
{
	int		i;
	int		size;
	char	swap;

	i = 0;
	size = ft_strlen(str);
	while (i < (size / 2))
	{
		swap = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = swap;
		i++;
	}
	str[size] = '\0';
	return (str);
}

static void	prepare_to_convert(int *n, int *is_neg, int *len)
{
	*is_neg = 0;
	*len = num_len(*n);
	if (*n < 0)
	{
		*is_neg = 1;
		*len += 1;
		*n = -(*n);
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_neg;
	int		len;
	char	*res;

	if (n == 0)
		return ("0");
	prepare_to_convert(&n, &is_neg, &len);
	res = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (n)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (is_neg)
		res[i] = '-';
	return (str_rev(res));
}
