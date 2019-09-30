/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:51:17 by guroux            #+#    #+#             */
/*   Updated: 2019/09/30 22:22:02 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>
# define CURSOR 1 << 0
# define SELECTED 1 << 1

typedef struct				s_select
{
		char				*str;
		char				status;
		struct s_select		*next;
		struct s_select		*prev;
}							t_select;

/*
** main.c
*/

t_select 					**repeat_head(t_select **head);
struct termios				repeat_termios(struct termios *s_termios);

/*
** term.c
*/

int							init_term(struct termios s_termios);
int							reset_term(struct termios s_termios);
void						switch_screen(int action);

/*
** select.c
*/

int							readterm(t_select **head);

/*
** tools.c
*/

int							ft_putcher(int c);
int							calc_longest(t_select *head);
int							args_number(t_select *head);

/*
** move.c
*/

void						move_left(t_select *list);
void						move_right(t_select *list);
void						handle_select(t_select *head);
void						move_down(t_select *list, int arg_per_line);
void						move_up(t_select *list, int arg_per_line);

/*
** print.c
*/

int							print_list(t_select *head);
int							verify_size(int arg_per_line, int args, struct winsize ws);

/*
** list.c
*/

t_select					*create_list(int ac, char **av);
void						remove_node(t_select **head);
void						del_list(t_select *node);

/*
** signal.c
*/

void						handle_signal(int sig);

#endif
