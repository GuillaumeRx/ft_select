/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:51:17 by guroux            #+#    #+#             */
/*   Updated: 2019/09/11 22:14:08 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft.h"
# include <termcap.h>
# include <termios.h>
# include <signal.h>

/*
** term.c
*/

int		init_term();

/*
** select.c
*/

int		readterm();

#endif
