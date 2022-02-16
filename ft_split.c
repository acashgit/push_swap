/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:41:01 by acash             #+#    #+#             */
/*   Updated: 2021/12/01 16:41:03 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_newword(char *s, char c, size_t *i)
{
	char	*arr;
	size_t	len;
	size_t	start;

	len = 0;
	while (s[*i] == c && s[*i])
	{
		(*i)++;
	}
	start = *i;
	while (s[*i] != c && s[*i])
	{
		len++;
		(*i)++;
	}
	arr = ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(arr, &s[start], len + 1);
	return (arr);
}

static char	**ft_mmyfree(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	word_count;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	string = ft_calloc(word_count + 1, sizeof(char *));
	if (string == NULL)
		return (NULL);
	while (i < word_count)
	{
		string[i] = ft_newword((char *)s, c, &j);
		if (string[i] == NULL)
		{
			return (ft_mmyfree(string));
		}
		i++;
	}
	string[i] = NULL;
	return (string);
}
