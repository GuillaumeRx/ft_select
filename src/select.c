/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:09 by guroux            #+#    #+#             */
/*   Updated: 2019/09/18 23:17:44 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		printspaces(int len)
{
	while (len != 0)
	{
		ft_putchar(' ');
		--len;
	}
}

static void		get_status(char status)
{
	char *reversed = tgetstr("mr", NULL);
	char *underline = tgetstr("us", NULL);
	
	if (status & CURSOR)
		tputs(underline, STDOUT_FILENO, ft_putcher);
	if (status & SELECTED)
		tputs(reversed, STDOUT_FILENO, ft_putcher);
}

static void		print_word(const t_select *word, int len)
{
	get_status(word->status);
	ft_putstr(word->str);
	tputs(tgetstr("ue", NULL), STDOUT_FILENO, ft_putcher);
	printspaces(len - ft_strlen(word->str));
}

static int		print_list(t_select *head, struct winsize ws)
{
	t_select	*tmp;
	int			len;
	int			arg_per_line;
	int			i;
	
	tmp = head;
	len = calc_longest(head);
	arg_per_line = ws.ws_col / (len + 1);
	i = 0;
	while (tmp != NULL)
	{
		print_word(tmp, len);
		++i;
		if (i == arg_per_line)
		{
			ft_putchar('\n');
			i = 0;
		}
		else if (tmp->next != NULL)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	return (1);
}

int				readterm(t_select *head)
{
	char	c;
	struct winsize ws;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	print_list(head, ws);
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
	{
		
	}
	tputs(tgetstr("ve", NULL), STDOUT_FILENO, ft_putcher);
	tputs(tgetstr("cl", NULL), STDOUT_FILENO, ft_putcher);
	return (1);
}
