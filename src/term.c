/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:55:09 by guroux            #+#    #+#             */
/*   Updated: 2019/09/10 13:26:51 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_termcap()
{
	int		ret;
	char	*term_typ;

	if(!(term_typ = getenv("TERM")))
	{
		ft_putendl_fd("ft_select: \"TERM\" not set.", STDERR_FILENO);
		return (0);
	}
	ret = tgetent(NULL, term_typ);
	if (ret == -1)
	{
		ft_putendl_fd("ft_select: Could not access Termcap database.", STDERR_FILENO);
		return (0);
	}
	if (ret == 0)
	{
		ft_putstr_fd("ft_select: terminal type ", STDERR_FILENO);
		ft_putstr_fd(term_typ, STDERR_FILENO);
		ft_putendl_fd("is not defined in Termcap database.", STDERR_FILENO);
		return (0);
	}
	return (1);
}
