/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:31 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 23:16:59 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n--)
	{
		if (*s1 != *(s2++))
			return (0);
		if (!*(s1++))
			return (1);
	}
	return (1);
}