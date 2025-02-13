/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:06 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 18:38:32 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#define QUOTE_LENGTH 2

static size_t	get_word_length(const char *str, const char delim, size_t nth);
static size_t	try_get_length_in_quote(const char **str);
static int		try_get_quote(const char *str);
static bool		is_quote(const char *str);

char	**ft_split_by_quote(const char *str, const char delim)
{
	char			**res;
	size_t			i;
	size_t			length;
	size_t			count;

	i = 1;
	length = get_word_length(str, delim, i);
	while (length != 0)
		length = get_word_length(str, delim, ++i);
	count = i - 1;
	res = ft_calloc(sizeof(char *), (count + 1));
	i = 0;
	while (i < count)
	{
		length = get_word_length(str, delim, 1);
		if (is_quote(str))
			++str;
		res[i++] = ft_strndup_malloc(str, length);
		str += length;
		if (is_quote(str))
			++str;
		while (*str == delim && *str != '\0')
			++str;
	}
	return (res);
}

static size_t	get_word_length(const char *str, char delim, size_t nth)
{
	size_t	count;
	size_t	length;

	count = 0;
	while (*str != '\0' && count != nth)
	{
		length = 0;
		while (*str == delim)
			++str;
		while (*str != delim && *str != '\0')
		{
			length += try_get_length_in_quote(&str);
			if (length == 0)
				++length;
			++str;
		}
		++count;
	}
	if (count < nth)
	{
		length = 0;
	}
	return (length);
}

static size_t	try_get_length_in_quote(const char **str)
{
	char	quote;
	size_t	length;

	quote = try_get_quote(*str);
	if (quote == 0)
	{
		return (0);
	}
	length = 0;
	++*str;
	while (**str != quote && **str != '\0')
	{
		++length;
		++*str;
	}
	return (length);
}

static int	try_get_quote(const char *str)
{
	char	quote;

	quote = 0;
	if (*str == '\'')
	{
		quote = '\'';
	}
	else if (*str == '"')
	{
		quote = '"';
	}
	return (quote);
}

static bool	is_quote(const char *str)
{
	bool	is_quote;

	is_quote = false;
	if (*str == '\'')
	{
		is_quote = true;
	}
	else if (*str == '"')
	{
		is_quote = true;
	}
	return (is_quote);
}
