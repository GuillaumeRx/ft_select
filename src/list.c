/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:28:27 by guroux            #+#    #+#             */
/*   Updated: 2019/09/30 21:33:23 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		remove_node(t_select **head)
{
	t_select *prev;
	t_select *act;
	t_select *next;

	act = *head;
	next = (*head)->next;
	while (act != NULL)
	{
		if (act->status & CURSOR)
		{
			if (act == *head)
			{
				move_right(*head);
				*head = (*head)->next;
				return;
			}
			else if (next == NULL)
			{
				move_right(*head);
				prev->next = NULL;
				return ;
			}
			move_right(*head);
			prev->next = next;
			return ;
		}
		prev = act;
		act = act->next;
		next = next->next;
	}
	return ;
}

void	add_node(t_select **lst, t_select *new)
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

t_select	*create_list(int ac, char **av)
{
	int			i;
	t_select	*head;
	t_select	*tmp;
	
	i = ac - 1;
	head = NULL;
	while (i != 0)
	{
		if (i == ac - 1)
			head = new_node(av[i]);
		else
		{
			tmp = new_node(av[i]);
			if (i == 1)
				tmp->status = tmp->status | CURSOR;
			add_node(&head, tmp);
		}
		--i;
	}
	return (head);
}

void		del_list(t_select *node)
{
	if (node)
	{
		ft_strdel(&(node->str));
		del_list(node->next);
		free(node);
		node = NULL;
	}
}