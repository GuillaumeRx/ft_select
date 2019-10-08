/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:54:49 by guroux            #+#    #+#             */
/*   Updated: 2019/10/08 17:50:55 by guroux           ###   ########.fr       */
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

void	move_down(t_select *list, int arg_per_line)
{
	t_select	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->status & CURSOR)
		{
			tmp->status ^= CURSOR;
			while (arg_per_line != 0 && tmp->next != NULL)
			{
				--arg_per_line;
				tmp = tmp->next;
			}
			tmp->status |= CURSOR;
			return ;
		}
		tmp = tmp->next;
	}
}

void	move_up(t_select *list, int arg_per_line)
{
	t_select	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->status & CURSOR)
		{
			tmp->status ^= CURSOR;
			while (arg_per_line != 0 && tmp->prev != NULL)
			{
				--arg_per_line;
				tmp = tmp->prev;
			}
			tmp->status |= CURSOR;
			return ;
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
			return ;
		}
		tmp = tmp->next;
	}
}

void	move_left(t_select *list)
{
	t_select *tmp;

	tmp = list;
	if (tmp->status & CURSOR)
	{
		tmp->status ^= CURSOR;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->status |= CURSOR;
		return ;
	}
	while (tmp != NULL)
	{
		if (tmp->status & CURSOR)
		{
			tmp->prev->status |= CURSOR;
			tmp->status ^= CURSOR;
			return ;
		}
		tmp = tmp->next;
	}
}
