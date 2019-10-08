/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:21:58 by guroux            #+#    #+#             */
/*   Updated: 2019/10/08 18:02:34 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				verify_size(int arg_per_line, int args, struct winsize ws)
{
	if ((args / arg_per_line) >= ws.ws_row)
		return (0);
	return (1);
}

static void		get_status(char status)
{
	if (status & CURSOR)
		tputs(tgetstr("us", NULL), 2, ft_putcher);
	if (status & SELECTED)
		tputs(tgetstr("mr", NULL), 2, ft_putcher);
}

static void		print_word(const t_select *word, int len)
{
	int pad;

	pad = len - ft_strlen(word->str);
	get_status(word->status);
	ft_putstr_fd(word->str, 2);
	tputs(tgetstr("me", NULL), 2, ft_putcher);
	while (pad != 0)
	{
		ft_putchar_fd(' ', 2);
		--pad;
	}
}

static void		print_list(t_select *head, int len, int arg_per_line)
{
	t_select	*tmp;
	int			i;

	i = 0;
	tmp = head;
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

int				handle_print(t_select *head)
{
	int				len;
	int				arg_per_line;
	struct winsize	ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	len = calc_longest(head);
	arg_per_line = ws.ws_col / (len + 1);
	if (verify_size(arg_per_line, args_number(head), ws))
		print_list(head, len, arg_per_line);
	else
		ft_putendl_fd("The window is too small", STDERR_FILENO);
	return (1);
}
