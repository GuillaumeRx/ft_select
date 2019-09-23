/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:28:27 by guroux            #+#    #+#             */
/*   Updated: 2019/09/23 12:27:11 by guroux           ###   ########.fr       */
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
			else
			{
				move_right(*head);
				prev->next = next;
				return ;
			}
		}
		prev = act;
		act = act->next;
		next = next->next;
	}
	return ;
}

void	handle_select(t_select *head)
{
	t_select *tmp;
	
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->status & CURSOR)
		{
			if (tmp->status & SELECTED)
				tmp->status = tmp->status ^ SELECTED;
			else
				tmp->status = tmp->status | SELECTED;
		}
		tmp = tmp->next;
	}
}

void	move_right(t_select *list)
{
	t_select *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->status & CURSOR)
		{
			if (tmp->next)
			{
				tmp->status = tmp->status ^ CURSOR;
				tmp->next->status = tmp->next->status | CURSOR;
			}
			else
			{
				tmp->status = tmp->status ^ CURSOR;
				list->status = list->status | CURSOR;
			}
			return;
		}
		tmp = tmp->next;
	}
}

void	move_left(t_select *list)
{
	t_select *prev;
	t_select *next;

	prev = list;
	next = list->next;
	if (prev->status & CURSOR)
	{
		prev->status = prev->status ^ CURSOR;
		while (prev->next != NULL)
			prev = prev->next;
		prev->status = prev->status | CURSOR;

	}
	else
	{
		while (prev->next != NULL)
		{
			if (next->status & CURSOR)
			{
				next->status = next->status ^ CURSOR;
				prev->status = prev->status | CURSOR;
				return;
			}
			prev = prev->next;
			next = next->next;
		}

	}
}

void	add_node(t_select **lst, t_select *new)
{
	new->next = *lst;
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