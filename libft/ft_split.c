/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:50 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/18 15:07:08 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (words);
}

static void	free_result(char **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

static char	*allocating(const char *start, const char *end)
{
	int		len;
	char	*word;

	len = end - start;
	word = (char *) malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static char	**process_string(const char *s, char c, char **result)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			result[i] = allocating(start, s);
			if (result[i] == NULL)
			{
				free_result(result, i);
				return (NULL);
			}
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	int			words;
	char		**result;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **) malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (process_string(s, c, result));
}
