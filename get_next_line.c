/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:31 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/19 15:02:42 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static t_list *stash;
	int			len;
	
	len = 1;
	stash = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	ft_read_extract_to_stash(fd, &stash, &len);
	if (stash == NULL)
		return (NULL);
	ft_extract_line(stash, &line);	
	return (line);
}

void	ft_read_extract_to_stash(int fd, t_list **stash, int *len)
{
	char	*buffer;
	int		i;
	
	i = 0;
	while (!found_newline(*stash) && *len != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return;
		*len = (int)read(fd, buffer, BUFFER_SIZE);
		if (*stash == NULL && *len == 0 || *len == -1)
			free(buffer);
			return;
		buffer[*len] = '/0';
		ft_add_to_stash(stash, buffer, *len);
		free(buffer)
	}
}

void	ft_add_to_stash(t_list **stash, char *buffer, int *len)
{
	int	i;
	t_list *last;
	t_list *newnode;

	i = 0;
	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return;
	newnode->next = NULL;
	newnode->content = malloc(sizeof(char) * (*len + 1));
	if (newnode->content == NULL)
		return;
	while (buffer[i] && i < *len)
	{
		newnode->content[i] = buffer[i];
		i++;
	}
	newnode->content[i] = '\n';
	if (*stash == NULL)
	{
		*stash = newnode;
		return;
	}
	last = ft_get_lst_last(*stash);
	last->next = newnode;
}

void	ft_extract_line(t_list stash, char **line)
{
	
}
