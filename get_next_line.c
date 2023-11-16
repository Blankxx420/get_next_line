/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:31 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:22 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int index;
	char *buffer;
	buffer = malloc(sizeof(char)* BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (read(fd,buffer,BUFFER_SIZE))
	{
		if (buffer[index] == '\n')
			
	}
}