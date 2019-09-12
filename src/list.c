/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:28:27 by guroux            #+#    #+#             */
/*   Updated: 2019/09/12 19:45:15 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*create_list(int ac, char **av)
{
	int			i;
	t_select	*head;
	t_select	*tmp;

	i = 0;
	while (i < ac)
	{
		if (i == 0)
		{
			if (!(head = (t_select *)malloc(sizeof(t_select))))
				return (NULL);
			if (!(head->str = ft_strdup(av[i])))
			{
				free(head);
				return (NULL);
			}
			head->next = NULL;
		}
		else
		{
			if (!(tmp = (t_select *)malloc(sizeof(t_select))))
				return (NULL);
			if (!(tmp->str = ft_strdup(av[i])))
				return (NULL);
			bite
		}
	}
}