/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:21:39 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:14:04 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_options(t_env *e)
{
	t_option		*t;
	struct winsize	ws;

	(e == NULL) ? e = g_glob_env : NULL;
	t = e->first_option;
	ioctl(0, TIOCGWINSZ, &ws);
	tputs(tgetstr("cl", NULL), 1, ft_tputs);
	while (t)
	{
		if ((t->col_offset + ft_strlen(t->name)) > ws.ws_col || ws.ws_col < 30)
		{
			tputs(tgoto(tgetstr("cl", NULL), t->col_offset, t->row), 1,
																	ft_tputs);
			ft_putstr_fd("Window too small to display options", e->term_fd);
			return ;
		}
		tputs(tgoto(tgetstr("cm", NULL), t->col_offset, t->row), 1, ft_tputs);
		(t == e->curr_option) ? tputs(tgetstr("us", NULL), 1, ft_tputs) : 0;
		(t->marked == 1) ? tputs(tgetstr("mr", NULL), 1, ft_tputs) : 0;
		ft_putstr_fd(t->name, e->term_fd);
		tputs(tgetstr("ue", NULL), 1, ft_tputs);
		tputs(tgetstr("me", NULL), 1, ft_tputs);
		t = t->next;
	}
}

void	return_selected(t_env *e)
{
	t_option *opts;

	opts = e->first_option;
	end_term(e);
	while (opts)
	{
		if (opts->marked)
		{
			ft_putstr_fd(opts->name, STDOUT_FILENO);
			if (opts->next)
				ft_putchar_fd(' ', e->term_fd);
		}
		opts = opts->next;
	}
	ft_putchar_fd('\n', e->term_fd);
	exit(EXIT_SUCCESS);
}
