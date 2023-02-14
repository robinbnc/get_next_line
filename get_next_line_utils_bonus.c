/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:41:47 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/20 21:45:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		return (i + 1);
	else
		return (i);
}

void	buff_init(char buff[][BUFFER_SIZE + 1])
{
	int	i;

	i = 0;
	if (buff[1024][0])
	{
		while (i < 1025)
		{
			buff[1024][0] = '\0';
			i ++;
		}
	}
}
