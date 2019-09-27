/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:14:45 by guroux            #+#    #+#             */
/*   Updated: 2019/09/27 18:54:53 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putcher(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
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
