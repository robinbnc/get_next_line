/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:59:19 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/20 21:45:48 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_str(char *s, char *buffer)
{
	char	*dest;
	int		i;
	int		j;
	int		buff_len;

	i = 0;
	j = 0;
	buff_len = ft_strlen(buffer);
	dest = malloc(sizeof(char) + (ft_strlen(s) + buff_len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	free(s);
	while (j < buff_len && buffer[j - 1] != '\n')
	{
		dest[i] = buffer[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i] && s[i - 1] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrimbuff(char *dest, char *src, char **str)
{
	int		i;

	i = 0;
	if (!src[0])
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*str = create_str(*str, dest);
	if (str == NULL)
		return (NULL);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	int			ret;

	ret = 1;
	str = ft_strdup("");
	buff_init(buffer);
	if (!str || BUFFER_SIZE < 1 || fd == -1
		|| !ft_strtrimbuff(buffer[fd], &buffer[fd][check_nl(buffer[fd])], &str))
		return (free(str), NULL);
	if (check_nl(str) && buffer[fd][0] != '\0')
		return (str);
	while (ret != 0)
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		if (ret == -1)
			break ;
		buffer[fd][ret] = '\0';
		str = create_str(str, buffer[fd]);
		if (str == NULL)
			return (NULL);
		if ((check_nl(str) || ret == 0) && str[0] != 0)
			return (str);
	}
	return (free(str), NULL);
}
