/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:07:44 by guroux            #+#    #+#             */
/*   Updated: 2019/09/25 18:58:31 by guroux           ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_select	*head;
	
	head = create_list(ac, av);
	repeat_head(&head);
	signal(SIGWINCH, handle_signal);
	if (init_term())
		readterm(&head);
	return (0);
}