/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 01:09:54 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 01:42:57 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	get_key(char *str)
{
	int	key;

	key = -1;
	key = str[0] == 10 && str[1] == 0 && str[2] == 0 ? KEY_RET : key;
	key = str[0] == 27 && str[1] == 0 && str[2] == 0 ? KEY_ESC : key;
	key = str[0] == 32 && str[1] == 0 && str[2] == 0 ? KEY_SPACE : key;
	key = str[0] == 27 && str[1] == 91 && str[2] == 65 ? KEY_UP : key;
	key = str[0] == 27 && str[1] == 91 && str[2] == 66 ? KEY_DOWN : key;
	key = str[0] == 27 && str[1] == 91 && str[2] == 68 ? KEY_LEFT : key;
	key = str[0] == 27 && str[1] == 91 && str[2] == 67 ? KEY_RIGHT : key;
	key = str[0] == 127 && str[1] == 0 && str[2] == 0 ? KEY_BSPCE : key;
	key = str[0] == 126 && str[1] == 0 && str[2] == 0 ? KEY_TILDE : key;
	return (key);
}

int			get_input(void)
{
	char	str[5];
	int		ret;

	ft_bzero(str, 5);
	if ((ret = (int)read(STDIN_FILENO, str, 4)) < 0)
		err(ERR_READ_ERROR, "");
	else
		return (get_key(str));
	return (EXIT_FAILURE);
}
