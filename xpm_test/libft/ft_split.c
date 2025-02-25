/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:06:51 by yuna              #+#    #+#             */
/*   Updated: 2024/06/10 11:42:53 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_total_words(char const *s, char c);
static void	split_words(char const *s, char c, int word_cnt, char **result);
static int	free_all(char **result, int i);

char	**ft_split(char const *s, char c)
{
	int		total_word;
	char	**result;

	total_word = get_total_words(s, c);
	result = (char **)malloc(sizeof(char *) * (total_word + 1));
	if (result == 0)
		return (0);
	result[total_word] = NULL;
	split_words(s, c, total_word, result);
	return (result);
}

static int	get_total_words(char const *s, char c)
{
	int	i;
	int	word_cnt;

	i = 1;
	word_cnt = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		++word_cnt;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			++word_cnt;
		++i;
	}
	return (word_cnt);
}

static void	split_words(char const *s, char c, int total_word, char **result)
{
	int		word_cnt;
	int		word_len;

	word_cnt = 0;
	while (word_cnt < total_word)
	{
		word_len = 0;
		while (*s == c)
			++s;
		while (s[word_len] && s[word_len] != c)
			++word_len;
		result[word_cnt] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (result[word_cnt] == NULL)
		{
			free_all(result, word_cnt);
			return ;
		}
		ft_strlcpy(result[word_cnt], s, word_len + 1);
		s = s + word_len;
		++word_cnt;
	}
}

static int	free_all(char **result, int i)
{
	while (--i >= 0)
		free(result[i]);
	free(result);
	return (0);
}
