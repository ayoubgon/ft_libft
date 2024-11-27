/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:18:49 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/16 13:19:11 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*ds;

	i = 0;
	if (!dest && !src)
		return (NULL);
	sr = (unsigned char *)src;
	ds = (unsigned char *)dest;
	if (ds > sr)
		while (len-- > 0)
			ds[len] = sr[len];
	else
	{
		while (i < len)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dest);
}