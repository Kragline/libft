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

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	size_t	inword;

	count = 0;
	inword = 0;
	while (*str)
	{
		if (*str != c && inword == 0)
		{
			inword = 1;
			count++;
		}
		else if (*str != c && inword == 1)
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
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[*index] && str[*index] != c)
	{
		word[i] = str[*index];
		(*index)++;
		i++;
	}
	word[i] = '\0';
	while (str[*index] == c)
		(*index)++;
	return (word);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**initialize_vars(char const *s, char c, size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
	return (malloc(sizeof(char *) * (count_words(s, c) + 1)));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	arr = initialize_vars(s, c, &i, &j);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = malloc_word(s, c, &i);
			if (!arr[j])
			{
				free_array(arr);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
