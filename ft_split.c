/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:21:41 by armarake          #+#    #+#             */
/*   Updated: 2024/12/22 18:21:41 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_our_char(char const c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	size_t	inword;

	count = 0;
	inword = 0;
	while (*str)
	{
		if (!is_our_char(*str, c) && inword == 0)
		{
			inword = 1;
			count++;
		}
		else if (is_our_char(*str, c) && inword == 1)
			inword = 0;
		str++;
	}
	return (count);
}

static char	*malloc_word(char const *str, char c, size_t *index)
{
	size_t	i;
	char	*word;

	i = 0;
	while (str[i] && !is_our_char(str[i], c))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[*index] && !is_our_char(str[*index], c))
	{
		word[i] = str[*index];
		(*index)++;
		i++;
	}
	word[i] = '\0';
	while (is_our_char(str[*index], c))
		(*index)++;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	arrlen;
	char	**arr;

	arrlen = count_words(s, c);
	arr = malloc(sizeof(char *) * (arrlen + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!is_our_char(s[i], c))
		{
			arr[j] = malloc_word(s, c, &i);
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
