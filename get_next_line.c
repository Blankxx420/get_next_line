/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:31 by brguicho          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/17 15:04:24 by brguicho         ###   ########.fr       */
=======
/*   Updated: 2023/11/16 17:57:52 by brguicho         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char *finalstr;
	int			len;
	
	len = 0;
	if (finalstr == NULL)
		finalstr = ft_calloc(sizeof(char), 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len = read(fd,buffer,BUFFER_SIZE);
	while (len > 0)
	{
		if (buffer[len - 1] == '\n')
			finalstr = ft_substr(buffer, len, len);
		len--;	
	}
	return (finalstr);
}