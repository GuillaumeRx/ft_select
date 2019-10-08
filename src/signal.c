/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:42:45 by guroux            #+#    #+#             */
/*   Updated: 2019/10/08 18:10:16 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		handle_signal(int sig)
{
	t_select		**head;
	struct termios	s_termios;

	head = repeat_head(NULL);
	s_termios = repeat_termios(NULL);
	if (sig == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 2, ft_putcher);
		handle_print(*head);
	}
	else if (sig == SIGTSTP)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGWINCH, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		reset_term(s_termios);
		ioctl(2, TIOCSTI, "\x1A");
		switch_screen(0);
	}
}

void		handle_signal_2(int sig)
{
	t_select		**head;
	struct termios	s_termios;

	head = repeat_head(NULL);
	s_termios = repeat_termios(NULL);
	if (sig == SIGINT || sig == SIGQUIT)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGWINCH, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		del_list(*head);
		reset_term(s_termios);
		switch_screen(0);
		exit(1);
	}
	else if (sig == SIGCONT)
	{
		switch_screen(1);
		init_term(s_termios);
		handle_print(*head);
	}
}
