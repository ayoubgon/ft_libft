/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:30:39 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/12 18:36:31 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s + start);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len_s < len)
		len = len_s;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && len > i)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
