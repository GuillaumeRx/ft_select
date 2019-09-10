/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:04:09 by guroux            #+#    #+#             */
/*   Updated: 2018/11/19 20:06:01 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while ((n /= 10) != 0)
		i++;
	return (i);
}
