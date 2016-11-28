/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:53:05 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 16:56:10 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	check_errno(char **tmp, int errno, char *msg)
{
	if (errno == ERR_NO_ARGS)
		*tmp = ft_strdup("No arguments given. Please provide arguments.");
	else if (errno == ERR_NO_TERMTYPE)
		*tmp = ft_strdup("Please define 'TERM' environment variable.");
	else if (errno == ERR_NO_ENTRY)
		*tmp = ft_nstrjoin("No entry found for termtype '", msg, "'");
	else if (errno == ERR_NODB)
		*tmp = ft_strdup("Terminfo/Termcaps Database cannot be found");
	else if (errno == ERR_CANT_RETRIEVE_TERM_ATTR)
		*tmp = ft_nstrjoin("Can't get terminal attributes for '", msg, "'");
	else if (errno == ERR_MALLOC)
		*tmp = ft_nstrjoin("Cannot assign memory '", msg, "'");
	else if (errno == ERR_READ_ERROR)
		*tmp = ft_strdup("Error reading input");
	else
		*tmp = ft_strdup("No further details");
}

void		err(int errno, char *msg)
{
	static char	*err = "\033[01;31mError!\033[0m -- ";
	char		*err_msg;
	char		*tmp;

	check_errno(&tmp, errno, msg);
	err_msg = ft_strjoin(err, tmp);
	ft_putendl(err_msg);
	free(tmp);
	free(err_msg);
	exit(EXIT_FAILURE);
}
