/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:55:09 by guroux            #+#    #+#             */
/*   Updated: 2019/10/08 18:20:29 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			switch_screen(int action)
{
	char *term;

	if ((term = getenv("TERM")) != NULL
	&& ft_strcmp(term, "xterm-256color") == 0)
	{
		if (action)
			ft_putstr_fd("\033[?1049h\033[H", 2);
		else
			ft_putstr_fd("\033[?1049l", 2);
	}
}

static int		tgetent_err(int ret, char *term_typ)
{
	if (ret == -1)
	{
		ft_putendl_fd("ft_select: Could not access Termcap database."
		, STDERR_FILENO);
		return (0);
	}
	if (ret == 0)
	{
		ft_putstr_fd("ft_select: terminal type ", STDERR_FILENO);
		ft_putstr_fd(term_typ, STDERR_FILENO);
		ft_putendl_fd("is not defined in Termcap database.", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int		init_termcap(void)
{
	char	*term_typ;

	if (!(term_typ = getenv("TERM")))
	{
		ft_putendl_fd("ft_select: \"TERM\" not set.", STDERR_FILENO);
		return (0);
	}
	if (!(tgetent_err(tgetent(NULL, term_typ), term_typ)))
		return (0);
	if (!(tgetstr("cl", NULL)) || !(tgetstr("vi", NULL))
	|| !(tgetstr("ks", NULL)) || !(tgetstr("ve", NULL))
	|| !(tgetstr("mr", NULL)) || !(tgetstr("me", NULL))
	|| !(tgetstr("us", NULL)))
	{
		ft_putendl_fd("ft_select: Terminal not supported.", STDERR_FILENO);
		return (0);
	}
	return (1);
}

int				init_term(struct termios s_termios)
{
	signal(SIGCONT, handle_signal_2);
	signal(SIGTSTP, handle_signal);
	signal(SIGINT, handle_signal_2);
	signal(SIGQUIT, handle_signal_2);
	if (init_termcap())
	{
		s_termios.c_lflag &= ~(ICANON);
		s_termios.c_lflag &= ~(ECHO);
		s_termios.c_cc[VMIN] = 1;
		s_termios.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSAFLUSH, &s_termios) == -1)
			return (0);
		tputs(tgetstr("vi", NULL), 2, ft_putcher);
		tputs(tgetstr("ks", NULL), 2, ft_putcher);
		return (1);
	}
	return (0);
}

int				reset_term(struct termios s_termios)
{
	if (tcsetattr(0, TCSAFLUSH, &s_termios) == -1)
		return (0);
	tputs(tgetstr("ve", NULL), 2, ft_putcher);
	return (1);
}
