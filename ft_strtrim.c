/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:30:12 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/12 18:36:28 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_check_set(((char)*s1), set))
		s1++;
	end = ft_strlen(s1);
	while (end != 0 && ft_check_set((char)s1[end - 1], set))
		end--;
	str = (char *)malloc(end + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, end + 1);
	return (str);
}
