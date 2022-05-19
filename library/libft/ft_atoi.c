/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:33:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 05:59:39 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	nb;
	long int	sign;

	nb = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - '0');
		i ++;
	}
	return (nb * sign);
}
