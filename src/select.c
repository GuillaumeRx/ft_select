/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:09 by guroux            #+#    #+#             */
/*   Updated: 2019/10/08 18:07:54 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		handle_keypress(char buff[5], t_select **head)
{
	int					len;
	struct winsize		ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	len = calc_longest(*head);
	if (verify_size(ws.ws_col / (len + 1), args_number(*head), ws))
	{
		if (ft_strcmp(buff, tgetstr("kl", NULL)) == 0)
			move_left(*head);
		else if (ft_strcmp(buff, tgetstr("kr", NULL)) == 0)
			move_right(*head);
		else if (ft_strcmp(buff, tgetstr("kd", NULL)) == 0)
			move_down(*head, ws.ws_col / (len + 1));
		else if (ft_strcmp(buff, tgetstr("ku", NULL)) == 0)
			move_up(*head, ws.ws_col / (len + 1));
		else if (ft_strcmp(buff, " ") == 0)
			handle_select(*head);
		else if ((buff[0] == 127 && buff[1] == 0)
		|| ft_strcmp(buff, "\x1B[3~") == 0)
			remove_node(head);
		else if (ft_strcmp(buff, "\e") == 0)
			return (-1);
		return (1);
	}
	return (0);
}

int				readterm(t_select **head)
{
	char	buff[4 + 1];
	int		ret;

	if (head && *head)
		handle_print(*head);
	while ((ret = read(STDIN_FILENO, buff, 4)))
	{
		buff[ret] = '\0';
		ret = 0;
		if ((ret = handle_keypress(buff, head)) == 1)
		{
			tputs(tgetstr("cl", NULL), 2, ft_putcher);
			if (head && *head)
				handle_print(*head);
			else
				break ;
		}
		else if (ret == -1)
			return (0);
		else if (ft_strcmp("\n", buff) == 0)
			return (1);
		ft_strclr(buff);
	}
	return (0);
}
