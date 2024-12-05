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

	if (!needle || needle[0] == '\0')
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

/*#include <stdio.h>
#include <string.h>

int main() {
    char haystack1[] = "This is a haystack";
    char needle1[] = "hay";
    char *result1 = ft_strnstr(haystack1, needle1, strlen(haystack1));

    char haystack2[] = "This is a haystack";
    char needle2[] = "haystack";
    char *result2 = ft_strnstr(haystack2, needle2, strlen(haystack2));

    char haystack3[] = "This is a haystack";
    char needle3[] = "haystack2"; 
    char *result3 = ft_strnstr(haystack3, needle3, strlen(haystack3));

    char haystack4[] = "This is a haystack";
    char needle4[] = "hay";
    char *result4 = ft_strnstr(haystack4, needle4, 5); // Limit to 5 characters

    char haystack5[] = "This is a haystack";
    char needle5[] = ""; // Empty needle
    char *result5 = ft_strnstr(haystack5, needle5, strlen(haystack5));

    char haystack6[] = "This is a haystack";
    char *needle6 = NULL; // NULL needle
    char *result6 = ft_strnstr(haystack6, needle6, strlen(haystack6));

    printf("Test 1: %s\n", result1); // Expected: haystack
    printf("Test 2: %s\n", result2); // Expected: haystack
    printf("Test 3: %s\n", result3); // Expected: NULL
    printf("Test 4: %s\n", result4); // Expected: NULL (not found in 5 chars)
    printf("Test 5: %s\n", result5); // Expected: This is a haystack
    printf("Test 6: %s\n", result6); // Expected: This is a haystack

    return 0;
}*/