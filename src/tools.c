/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:14:45 by guroux            #+#    #+#             */
/*   Updated: 2019/10/02 17:22:23 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clear_term(void)
{
	tputs(tgetstr("cl", NULL), 2, ft_putcher);
}

int		ft_putcher(int c)
{
	return (write(2, &c, 1));
}

int		calc_longest(t_select *head)
{
	t_select	*tmp;
	size_t		len;
	
	tmp = head;
	len = 0;
	while (tmp != NULL)
	{
		if (ft_strlen(tmp->str) > len)
			len = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (len);
}

int		args_number(t_select *head)
{
	t_select	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
