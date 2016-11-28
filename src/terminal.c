/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:08:41 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:14:59 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_term(t_env *e)
{
	if (e == NULL)
		e = g_glob_env;
	e->new_config = e->default_config;
	e->new_config.c_iflag |= IGNBRK;
	e->new_config.c_lflag |= ISIG;
	e->new_config.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | IEXTEN);
	e->new_config.c_cc[VMIN] = 1;
	e->new_config.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &e->new_config);
	tputs(tgetstr("ti", NULL), 1, ft_tputs);
	tputs(tgetstr("vi", NULL), 1, ft_tputs);
	tputs(tgetstr("cl", NULL), 1, ft_tputs);
}

void	end_term(t_env *e)
{
	if (e == NULL)
		e = g_glob_env;
	tputs(tgetstr("cl", NULL), 1, ft_tputs);
	tputs(tgetstr("ve", NULL), 1, ft_tputs);
	tputs(tgetstr("te", NULL), 1, ft_tputs);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &e->default_config);
}
