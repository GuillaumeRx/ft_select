/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:42:45 by guroux            #+#    #+#             */
/*   Updated: 2019/09/25 18:50:25 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		handle_signal(int sig)
{
	t_select **head;

	head = repeat_head(NULL);
	if (sig == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), STDOUT_FILENO, ft_putcher);
		print_list(*head);
	}
}