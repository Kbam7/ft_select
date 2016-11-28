/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:56:01 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:11:00 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	resize(int sig)
{
	(void)sig;
	set_opt_positions(NULL);
	print_options(NULL);
}

static void	stop(int sig)
{
	char	cp[2];

	cp[0] = 032;
	cp[1] = 0;
	(void)sig;
	end_term(NULL);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void	restart(int sig)
{
	(void)sig;
	init_term(NULL);
	signal(SIGTSTP, stop);
	print_options(NULL);
}

static void	end(int sig)
{
	(void)sig;
	end_term(NULL);
	exit(1);
}

void		check_signals(void)
{
	signal(SIGWINCH, resize);
	signal(SIGTSTP, stop);
	signal(SIGCONT, restart);
	signal(SIGINT, end);
	signal(SIGQUIT, end);
}
