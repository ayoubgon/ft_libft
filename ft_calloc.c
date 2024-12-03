/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:12:15 by adehbi            #+#    #+#             */
/*   Updated: 2024/12/03 17:02:38 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;
	int		check;

	if (size == 0)
		return (malloc(0));
	check = count * size;
	if (check / size != count)
		return (NULL);
	cal = malloc(count * size);
	if (!cal)
		return (NULL);
	ft_bzero (cal, count * size);
	return (cal);
}
