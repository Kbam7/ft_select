/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 00:28:49 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:14:43 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_option	*new_option(char *name, t_env *e)
{
	t_option	*new;

	if ((new = (t_option *)malloc(sizeof(t_option))) != NULL)
	{
		new->name = name;
		new->marked = 0;
		new->next = NULL;
		new->prev = e->last_option;
		e->last_option = new;
	}
	else
		err(ERR_MALLOC, "ft_get_options: add_option: new_option:");
	return (new);
}

static int		add_option(char *name, t_option **list, t_env *e)
{
	t_option	*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_option(name, e);
	}
	else
	{
		*list = new_option(name, e);
		e->first_option = *list;
	}
	return (EXIT_SUCCESS);
}

void			set_opt_positions(t_env *e)
{
	struct winsize	ws;
	t_option		*opt;
	int				i;

	if (e == NULL)
		e = g_glob_env;
	i = 0;
	opt = e->first_option;
	ioctl(0, TIOCGWINSZ, &ws);
	while (opt)
	{
		opt->col = (i / ws.ws_row);
		opt->row = (i % ws.ws_row);
		opt->col_offset = get_offset(ws.ws_row, opt->col, opt);
		i++;
		opt = opt->next;
	}
}

int				ft_get_options(int ac, char **av, t_env *e)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		add_option(av[i], &e->options, e);
		++i;
	}
	e->curr_option = e->first_option;
	return (i - 1);
}
