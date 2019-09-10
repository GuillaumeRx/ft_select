/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:07:44 by guroux            #+#    #+#             */
/*   Updated: 2019/09/10 13:17:42 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(void)
{
	struct termios s_termios;
	struct termios s_termios_bkp;

	if (init_termcap())
	{
		if (tcgetattr(0, &s_termios) == -1 || tcgetattr(0, &s_termios_bkp) == -1)
			return (-1);
		s_termios.c_lflag &= ~(ICANON);
		s_termios.c_lflag &= ~(ECHO);
		if (tcsetattr(0, 0, &s_termios) == -1)
			return (-1);
	}
	return (0);
}
