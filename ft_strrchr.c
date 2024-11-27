/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:29:34 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/16 16:54:53 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	ch;

	ch = (char)c;
	i = ft_strlen(str);
	while (str[i] != ch && i > 0)
		i--;
	if (str[i] == ch)
		return ((char *) &str[i]);
	return (NULL);
}
