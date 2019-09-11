/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:09 by guroux            #+#    #+#             */
/*   Updated: 2019/09/11 22:14:01 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		readterm()
{
	char	c;
	int column_count;
	int line_count;

	column_count = tgetnum("co");
	line_count = tgetnum("li");
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
	{

	}
	return (1);
}
