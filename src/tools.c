/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:14:45 by guroux            #+#    #+#             */
/*   Updated: 2019/09/12 19:24:05 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putcher(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int		calc_longest(int ac, char **av)
{
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > len)
			len = ft_strlen(av[i]);
		++i;
	}
	return (len);
}
