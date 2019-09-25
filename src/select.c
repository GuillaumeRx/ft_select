/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:09 by guroux            #+#    #+#             */
/*   Updated: 2019/09/25 18:49:58 by guroux           ###   ########.fr       */
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
	tputs(tgetstr("me", NULL), STDOUT_FILENO, ft_putcher);
	printspaces(len - ft_strlen(word->str));
}

static int		handle_keypress(char buff[5], t_select **head)
{
	if (ft_strcmp(buff, tgetstr("kl", NULL)) == 0)
	{
		move_left(*head);
		return (1);
	}
	if (ft_strcmp(buff, tgetstr("kr", NULL)) == 0)
	{
		move_right(*head);
		return (1);
	}
	if (ft_strcmp(buff, " ") == 0)
	{
		handle_select(*head);
		return (1);
	}
	if ((buff[0] == 127 && buff[1] == 0) || ft_strcmp(buff, "\x1B[3~") == 0)
	{
		remove_node(head);
		return (1);
	}
	if (ft_strcmp(buff, "\e") == 0)
	{
		tputs(tgetstr("ve", NULL), STDOUT_FILENO, ft_putcher);
		exit(1);
	}
	return (0);
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

int				readterm(t_select **head)
{
	char	buff[4 + 1];
	int		ret;
	
	if (head && *head)
		print_list(*head);
	while ((ret = read(STDIN_FILENO, buff, 4)))
	{
		buff[ret] = '\0';
		if (handle_keypress(buff, head))
		{
			tputs(tgetstr("cl", NULL), STDOUT_FILENO, ft_putcher);
			if (head && *head)
			{
				print_list(*head);
			}
			else
				break;
		}
		ft_strclr(buff);
	}
	tputs(tgetstr("ve", NULL), STDOUT_FILENO, ft_putcher);
	tputs(tgetstr("cl", NULL), STDOUT_FILENO, ft_putcher);
	return (1);
}
