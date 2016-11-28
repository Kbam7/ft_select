/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:16:30 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:11:52 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	remove_first(t_option *option, t_env *e)
{
	option->next->prev = NULL;
	e->first_option = option->next;
	e->curr_option = option->next;
	free(option);
	option = NULL;
	return (1);
}

static int	remove_last(t_option *option, t_env *e)
{
	option->prev->next = NULL;
	e->last_option = option->prev;
	e->curr_option = option->prev;
	free(option);
	option = NULL;
	return (1);
}

static int	remove_opt(t_option *option, t_env *e)
{
	option->prev->next = option->next;
	option->next->prev = option->prev;
	e->curr_option = option->next;
	free(option);
	option = NULL;
	return (1);
}

void		delete_option(t_env *e)
{
	int			res;
	t_option	*option;

	res = 0;
	option = e->curr_option;
	if (option == e->last_option && option == e->first_option)
	{
		end_term(e);
		exit(EXIT_SUCCESS);
	}
	if (option == e->first_option)
		res = remove_first(option, e);
	else if (option == e->last_option)
		res = remove_last(option, e);
	else
		res = remove_opt(option, e);
	e->n_options -= res;
	set_opt_positions(e);
}
