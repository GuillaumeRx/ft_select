/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:28:27 by guroux            #+#    #+#             */
/*   Updated: 2019/10/09 02:04:48 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			remove_node(t_select **head)
{
	t_select *act;

	act = *head;
	while (act != NULL)
	{
		if (act->status & CURSOR)
		{
			if (act == *head)
			{
				move_right(*head);
				ft_strdel(&((*head)->str));
				free(act);
				*head = (*head)->next;
				return ;
			}
			else
			{
				move_right(*head);
				free_node(act);
				return ;
			}
		}
		act = act->next;
	}
	return ;
}

void			add_node(t_select **lst, t_select *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}

t_select		*new_node(const char *str)
{
	t_select	*lst;

	if (!(lst = (t_select *)malloc(sizeof(t_select))))
		return (NULL);
	lst->str = ft_strdup(str);
	lst->next = NULL;
	bzero(&(lst->status), 1);
	return (lst);
}

t_select		*create_list(int ac, char **av)
{
	int			i;
	t_select	*head;
	t_select	*tmp;

	i = ac - 1;
	head = NULL;
	while (i != 0)
	{
		tmp = new_node(av[i]);
		if (i == 1)
			tmp->status |= CURSOR;
		if (i == ac - 1)
			head = tmp;
		else
			add_node(&head, tmp);
		--i;
	}
	return (head);
}

void			del_list(t_select *node)
{
	if (node)
	{
		ft_strdel(&(node->str));
		del_list(node->next);
		free(node);
		node = NULL;
	}
}
