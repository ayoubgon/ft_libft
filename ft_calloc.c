/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:12:15 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/16 12:09:37 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;
	size_t	check;

	if (size == 0)
	{
		cal = (void *)malloc(0);
		if (cal == NULL)
			return (NULL);
		return (cal);
	}
	check = count * size;
	if ((check / count) != size)
		return (NULL);
	cal = (void *)malloc(count * size);
	if (!cal)
		return (NULL);
	ft_bzero (cal, count * size);
	return (cal);
}
