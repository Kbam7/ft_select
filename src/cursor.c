/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:26:40 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 12:44:20 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	cursor_position(int key, t_env *e)
{
	if (key == KEY_UP)
		move_up(e);
	else if (key == KEY_DOWN)
		move_down(e);
	else if (key == KEY_LEFT)
		move_left(e);
	else if (key == KEY_RIGHT)
		move_right(e);
	else if (key == KEY_SPACE)
		mark_option(e);
}
