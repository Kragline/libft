/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:42:20 by armarake          #+#    #+#             */
/*   Updated: 2024/12/22 15:42:20 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*malloc_word(char const *str, size_t start, size_t end)
{
	size_t		i;
	size_t		len;
	char		*new;

	len = end - start + 1;
	if (len <= 0 || start >= ft_strlen(str))
		return (ft_strdup(""));
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		new[i] = str[start + i];
		i++;
	}
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]))
		j--;
	return (malloc_word(s1, i, j));
}
