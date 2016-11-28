/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 17:45:24 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 16:59:23 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_env(t_env *e)
{
	char	*term;
	int		ret;

	e->first_option = NULL;
	e->last_option = NULL;
	e->curr_option = NULL;
	e->n_options = 0;
	e->term_fd = open(ttyname(0), O_RDWR | O_NONBLOCK);
	if (!(term = getenv("TERM")))
		err(ERR_NO_TERMTYPE, "");
	if ((ret = tgetent(NULL, term)) < 1)
	{
		if (ret == 0)
			err(ERR_NO_ENTRY, term);
		else
			err(ERR_NODB, "");
	}
	if ((tcgetattr(STDIN_FILENO, &e->default_config)) < 0)
		err(ERR_CANT_RETRIEVE_TERM_ATTR, term);
}
