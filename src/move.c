/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:54:49 by guroux            #+#    #+#             */
/*   Updated: 2019/09/27 15:55:04 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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