/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:07:44 by guroux            #+#    #+#             */
/*   Updated: 2019/10/25 19:59:21 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select			**repeat_head(t_select **head)
{
	static t_select **mem;

	if (head == NULL)
		return (mem);
	else
	{
		mem = head;
		return (mem);
	}
}

struct termios		repeat_termios(struct termios *s_termios)
{
	static struct termios s_termios_bkp;

	if (s_termios == NULL)
		return (s_termios_bkp);
	else
	{
		s_termios_bkp = *s_termios;
		return (s_termios_bkp);
	}
}

static void			print_result(t_select *head)
{
	t_select	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->status & SELECTED)
		{
			if (i != 0)
				ft_putchar(' ');
			ft_putstr(tmp->str);
			++i;
		}
		tmp = tmp->next;
	}
}

static void			loop(int ac, char **av, struct termios s_termios)
{
	t_select *head;

	if ((head = create_list(ac, av)))
	{
		repeat_head(&head);
		repeat_termios(&s_termios);
		if (init_term(s_termios))
		{
			signal(SIGWINCH, handle_signal);
			if (readterm(&head))
			{
				clear_term();
				switch_screen(0);
				print_result(head);
			}
			else
				switch_screen(0);
		}
		del_list(head);
	}
}

int					main(int ac, char **av)
{
	struct termios		s_termios;

	if (ac < 2)
	{
		ft_putendl_fd("usage: ft_select [arg1] [arg2] [...]", 2);
		return (0);
	}
	switch_screen(1);
	if (tcgetattr(0, &s_termios) == -1)
		return (0);
	loop(ac, av, s_termios);
	reset_term(s_termios);
	return (0);
}
