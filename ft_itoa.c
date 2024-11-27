/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:15:34 by adehbi            #+#    #+#             */
/*   Updated: 2024/11/15 16:42:45 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_int(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_file(char *a, int i, int num)
{
	if (num == 0)
		a[0] = 48;
	while (num > 0)
	{
		a[i--] = ((num % 10) + 48);
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*i_toa;
	int		len_nb;
	long	num;

	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_nb = len_of_int(num);
	i_toa = (char *)malloc (len_nb + 1);
	if (i_toa == NULL)
		return (NULL);
	i_toa[len_nb] = '\0';
	if (num < 0)
	{
		i_toa[0] = '-';
		num *= -1;
	}
	if (num == 0)
		i_toa[0] = '0';
	ft_file(i_toa, len_nb - 1, num);
	return (i_toa);
}
