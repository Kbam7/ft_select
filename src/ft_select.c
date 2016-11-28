/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:22:55 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:13:40 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_env *e)
{
	int	key;

	key = 0;
	while (key != KEY_ESC)
	{
		cursor_position(key, e);
		if (key == KEY_TILDE || key == KEY_BSPCE)
			delete_option(e);
		if (key == KEY_RET)
			return_selected(e);
		print_options(e);
		g_glob_env = e;
		key = get_input();
	}
	if (key == KEY_ESC)
		end_term(e);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
		err(ERR_NO_ARGS, "");
	check_signals();
	init_env(&e);
	init_term(&e);
	e.n_options = ft_get_options(argc, argv, &e);
	set_opt_positions(&e);
	ft_select(&e);
	return (EXIT_SUCCESS);
}
