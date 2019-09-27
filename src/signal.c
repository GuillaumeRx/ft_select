/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:42:45 by guroux            #+#    #+#             */
/*   Updated: 2019/09/27 21:23:32 by guroux           ###   ########.fr       */
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
		tputs(tgetstr("cl", NULL), STDOUT_FILENO, ft_putcher);
		print_list(*head);
	}
	else if (sig == SIGTSTP)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGWINCH, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		reset_term(s_termios);
		ioctl(2, TIOCSTI, "\x1A");
	}
	else if (sig == SIGINT)
	{
		del_list(*head);
		reset_term(s_termios);
		exit(1);
	}
	else if (sig == SIGCONT)
	{
		init_term(s_termios);
		print_list(*head);
	}
}