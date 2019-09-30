/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:07:44 by guroux            #+#    #+#             */
/*   Updated: 2019/09/30 22:24:13 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select **repeat_head(t_select **head)
{
	static t_select **mem = NULL;
	
	if (head == NULL)
		return (mem);
	else
	{
		mem = head;
		return (mem);
	}	
}

struct termios	repeat_termios(struct termios *s_termios)
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

void	print_result(t_select *head)
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

int		main(int ac, char **av)
{
	t_select	*head;
	struct termios s_termios;
	
	switch_screen(1);
	if (tcgetattr(0, &s_termios) == -1)
			return (0);
	if ((head = create_list(ac, av)))
	{
		repeat_head(&head);
		repeat_termios(&s_termios);
		if (init_term(s_termios))
		{
			if (readterm(&head))
				print_result(head);
		}
		del_list(head);
	}
	reset_term(s_termios);
	switch_screen(0);
	return (0);
}