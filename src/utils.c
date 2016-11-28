/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 01:09:54 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 16:38:45 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	count_max(t_option *opt)
{
	int			max;
	int			col;

	max = 0;
	col = opt->col;
	while (opt->prev && (opt->prev)->col == col)
		opt = opt->prev;
	while (opt && opt->col == col)
	{
		if ((int)ft_strlen(opt->name) > max)
			max = (int)ft_strlen(opt->name);
		opt = opt->next;
	}
	return (max + 1);
}

int			ft_tputs(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int			get_offset(int l, int c, t_option *opt)
{
	int			x;
	int			tmp;

	x = 0;
	while (opt->prev)
		opt = opt->prev;
	while (c > 0)
	{
		x = opt->col_offset + count_max(opt);
		tmp = 0;
		while (tmp < l)
		{
			opt = opt->next;
			tmp++;
		}
		c--;
	}
	return (x);
}
