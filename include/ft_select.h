/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:22:16 by kbamping          #+#    #+#             */
/*   Updated: 2016/07/17 17:13:01 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termcap.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>

/*
**	Error numbers
*/
# define ERR_NO_ARGS					1000
# define ERR_NO_TERMTYPE				1001
# define ERR_NO_ENTRY					1002
# define ERR_NODB						1003
# define ERR_CANT_RETRIEVE_TERM_ATTR	1003
# define ERR_MALLOC						1004
# define ERR_READ_ERROR					1005

/*
**	Keys
*/
# define KEY_BSPCE		127
# define KEY_TILDE		126
# define KEY_DEL		127
# define KEY_RET		10
# define KEY_CTRLZ		26
# define KEY_ESC		27
# define KEY_SPACE		32
# define KEY_UP			65
# define KEY_DOWN		66
# define KEY_LEFT		68
# define KEY_RIGHT		67

typedef	struct	s_option
{
	char			*name;
	int				marked;
	int				col;
	int				row;
	int				col_offset;
	struct s_option	*prev;
	struct s_option	*next;
}				t_option;

typedef struct	s_env
{
	t_option		*options;
	t_option		*first_option;
	t_option		*last_option;
	t_option		*curr_option;
	size_t			n_options;
	int				term_fd;
	struct termios	default_config;
	struct termios	new_config;
}				t_env;

t_env			*g_glob_env;

/*
**	misc
*/
char			*ft_nstrjoin(char *s1, char *s2, char *s3);

/*
**	ft_select.c
*/
void			ft_select(t_env *e);

/*
**	signals.h
*/
void			check_signals(void);

/*
**	init.c
*/
void			init_env(t_env *e);

/*
**	terminal.c
*/
void			init_term(t_env *e);
void			end_term(t_env *e);

/*
**	options.c
*/
void			set_opt_positions(t_env *e);
int				ft_get_options(int ac, char **av, t_env *e);

/*
**	cursor.c
*/
void			cursor_position(int key, t_env *e);

/*
**	key_funcs.c
*/
void			move_up(t_env *e);
void			move_down(t_env *e);
void			move_left(t_env *e);
void			move_right(t_env *e);
void			mark_option(t_env *e);

/*
**	remove.c
*/
void			delete_option(t_env *e);

/*
**	output.c
*/
void			print_options(t_env *e);
void			return_selected(t_env *e);

/*
**	input.c
*/
int				get_input(void);

/*
**	utils.c
*/
int				ft_tputs(int c);
int				get_offset(int l, int c, t_option *opt);

/*
**	error.c
*/
void			err(int errno, char *msg);

#endif
