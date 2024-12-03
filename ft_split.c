/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:23:26 by adehbi            #+#    #+#             */
/*   Updated: 2024/12/03 19:24:11 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_all(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	count_word(const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		index;

	count = 0;
	i = 0;
	index = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && index == 0)
		{
			index = 1;
			count++;
		}
		else if (s[i] == c)
			index = 0;
		i++;
	}
	return (count);
}

static char	*alloc_word(const char *s, size_t start, size_t end)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < end)
		end = ft_strlen(s);
	len = end - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (start < end)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

static void	initiate_vars(size_t *i, int *st, int *en)
{
	*i = 0;
	*st = -1;
	*en = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**ar;
	size_t	i;
	int		st;
	int		en;
	
	// (1) && (i = 0, st = -1, en = -1);
	initiate_vars(&i, &st, &en);
	if (!s)
		return (NULL);
	ar = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	while (++en <= (int)ft_strlen(s))
	{
		if (s[en] != c && st < 0)
			st = en;
		else if ((s[en] == c || en == (int)ft_strlen(s)) && st >= 0)
		{
			ar[i++] = alloc_word(s, st, en);
			if (!ar[i - 1])
				return (ft_free_all(ar, i));
			st = -1;
		}
	}
	ar[i] = NULL;
	return (ar);
}
