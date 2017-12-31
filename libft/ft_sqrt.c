/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:28:16 by vvinogra          #+#    #+#             */
/*   Updated: 2017/11/04 14:28:17 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	while ((i * i) != nb && i <= 46340)
	{
		i++;
	}
	if ((i * i) == nb)
		return (i);
	return (0);
}
