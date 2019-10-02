/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:21:58 by guroux            #+#    #+#             */
/*   Updated: 2019/10/02 17:24:07 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			verify_size(int arg_per_line, int args, struct winsize ws)
{
		if ((args / arg_per_line) >= ws.ws_row)
			return (0);
		return (1);
}

static void		get_status(char status)
{
	char *reversed = tgetstr("mr", NULL);
	char *underline = tgetstr("us", NULL);
	
	if (status & CURSOR)
		tputs(underline, 2, ft_putcher);
	if (status & SELECTED)
		tputs(reversed, 2, ft_putcher);
}

static void		printspaces(int len)
{
	while (len != 0)
	{
		ft_putchar_fd(' ', 2);
		--len;
	}
}

static void		print_word(const t_select *word, int len)
{
	get_status(word->status);
	ft_putstr_fd(word->str, 2);
	tputs(tgetstr("me", NULL), 2, ft_putcher);
	printspaces(len - ft_strlen(word->str));
}

int		print_list(t_select *head)
{
	t_select	*tmp;
	int			len;
	int			arg_per_line;
	int			i;
	struct winsize ws;
	
	tmp = head;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	len = calc_longest(head);
	arg_per_line = ws.ws_col / (len + 1);
	i = 0;
	if (verify_size(arg_per_line, args_number(head), ws))
	{
		while (tmp != NULL)
		{
			print_word(tmp, len);
			++i;
			if (i == arg_per_line)
			{
				ft_putchar_fd('\n', 2);
				i = 0;
			}
			else if (tmp->next != NULL)
				ft_putchar_fd(' ', 2);
			tmp = tmp->next;
		}
	}
	else
		ft_putendl_fd("The window is too small", STDERR_FILENO);
	return (1);
}