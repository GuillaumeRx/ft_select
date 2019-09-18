/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:28:27 by guroux            #+#    #+#             */
/*   Updated: 2019/09/16 16:54:48 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	add_node(t_select **alst, t_select *new)
{
	new->next = *alst;
	*alst = new;
}

t_select		*new_node(const char *str)
{
	t_select	*lst;

	if (!(lst = (t_select *)malloc(sizeof(t_select))))
		return (NULL);
	lst->str = ft_strdup(str);
	lst->next = NULL;
	return (lst);
}

t_select	*create_list(int ac, char **av)
{
	int			i;
	t_select	*head;
	t_select	*tmp;
	
	i = ac - 1;
	while (i != 0)
	{
		if (i == ac - 1)
			head = new_node(av[i]);
		else
		{
			tmp = new_node(av[i]);
			add_node(&head, tmp);
		}
		--i;
	}
	return (head);
}