/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:20:41 by kbamping          #+#    #+#             */
/*   Updated: 2016/05/15 13:42:56 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = (char *)malloc(size);
	if (new_str == NULL)
		return (NULL);
	ft_memset(new_str, 0, size);
	return (new_str);
}
