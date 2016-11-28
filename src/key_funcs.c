/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:43:31 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 16:58:58 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_up(t_env *e)
{
	if (e->curr_option == e->first_option)
		e->curr_option = e->last_option;
	else
		e->curr_option = e->curr_option->prev;
}

void	move_down(t_env *e)
{
	if (e->curr_option == e->last_option)
		e->curr_option = e->first_option;
	else
		e->curr_option = e->curr_option->next;
}

void	move_left(t_env *e)
{
	t_option	*last;
	t_option	*curr;
	t_option	*opt;
	int			i;

	curr = e->curr_option;
	opt = e->curr_option;
	last = e->last_option;
	i = last->col;
	if (opt->col == 0)
	{
		i = ((last->row < opt->row) ? (i - 1) : i);
		while (!((opt->col == i) && (opt->row == curr->row)))
			opt = opt->next;
	}
	else
	{
		while (!((opt->col == (curr->col - 1)) && (opt->row == curr->row)))
			opt = opt->prev;
	}
	e->curr_option = opt;
}

void	move_right(t_env *e)
{
	t_option	*last;
	t_option	*curr;
	t_option	*opt;

	curr = e->curr_option;
	opt = e->curr_option;
	last = e->last_option;
	if (opt->col == last->col)
	{
		while (!((opt->col == 0) && (opt->row == curr->row)))
			opt = opt->prev;
		e->curr_option = opt;
	}
	else
	{
		opt = e->last_option;
		while (!((opt->col == (curr->col + 1)) && (opt->row == curr->row))
				&& !((opt->col == 0) && (opt->row == curr->row)))
			opt = opt->prev;
		e->curr_option = opt;
	}
}

void	mark_option(t_env *e)
{
	e->curr_option->marked = e->curr_option->marked == 1 ? 0 : 1;
	if (e->curr_option->marked == 1 && e->curr_option == e->last_option)
		e->curr_option = e->first_option;
	else if (e->curr_option->marked == 1)
		e->curr_option = e->curr_option->next;
}
