/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:51:17 by guroux            #+#    #+#             */
/*   Updated: 2019/09/16 16:01:59 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct				s_select
{
		char				*str;
		int					status;
		struct s_select		*next;
}							t_select;

/*
** term.c
*/

int							init_term();

/*
** select.c
*/

int							readterm(t_select *head);

/*
** tools.c
*/

int							ft_putcher(int c);
int							calc_longest(t_select *head);

/*
** list.c
*/

t_select					*create_list(int ac, char **av);

#endif
