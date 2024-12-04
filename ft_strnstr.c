/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:02:41 by armarake          #+#    #+#             */
/*   Updated: 2024/12/04 18:02:41 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h_ptr;
	const char	*n_ptr;

	if (!needle)
		return ((char *)haystack);
	h_ptr = haystack;
	n_ptr = needle;
	while (len > 0 && *haystack && *needle)
	{
		while (*needle != '\0' && *haystack == *needle)
		{
			haystack++;
			needle++;
		}
		if (*needle == '\0')
			return ((char *)h_ptr);
		needle = n_ptr;
		haystack++;
		h_ptr = haystack;
		len--;
	}
	return (NULL);
}
