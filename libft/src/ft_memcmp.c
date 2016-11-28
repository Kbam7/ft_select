/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 10:58:44 by kbamping          #+#    #+#             */
/*   Updated: 2016/05/15 10:59:28 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (s1 && s2)
	{
		ptr1 = (unsigned char *)s1;
		ptr2 = (unsigned char *)s2;
		while ((*ptr1 && *ptr2) && n)
		{
			if (*ptr1 != *ptr2)
				return (*ptr1 - *ptr2);
			ptr1++;
			ptr2++;
			--n;
		}
	}
	return (0);
}
