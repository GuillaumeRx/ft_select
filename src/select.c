/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:09 by guroux            #+#    #+#             */
/*   Updated: 2019/09/12 19:25:18 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		printlist(int ac, char **av)
{
	int		i;
	int		len;

	i = 0;
	len = calc_longest(ac, av);

	while (i < ac)
	{
		ft_putstr()
	}
}

int				readterm(int ac, char **av)
{
	char	c;
	struct winsize ws;
	
	(void)ac;
	(void)av;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
	{
		
	}
	return (1);
}