/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:09 by guroux            #+#    #+#             */
/*   Updated: 2019/09/17 16:58:04 by guroux           ###   ########.fr       */
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

static void		print_word(const t_select *word, int len)
{
	ft_putstr(word->str);
	printspaces(len - ft_strlen(word->str));
}

static int		print_list(t_select *head)
{
	t_select	*tmp;
	int			len;

	tmp = head;
	len = calc_longest(head);
	while (tmp != NULL)
	{
		print_word(tmp, len);
		if (tmp->next != NULL)
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
	print_list(head);
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
	{
		
	}
	return (1);
}
