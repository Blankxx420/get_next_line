/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:31 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/23 12:37:48 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stock;
	char		*line;

	if (!stock)
		stock = ft_calloc(sizeof(char), 1);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	if (!line)
		line = ft_calloc(sizeof(0), 1);
	ft_read_and_extract(fd, &stock);
	line = ft_get_line(stock, line);
	if (line && !*line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	stock = ft_clean_stock(stock);
	if (!*line && stock && !*stock)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	return (line);
}

void ft_read_and_extract(int fd, char **stock)
{
	char 	*buffer;
	int 	reed;
	
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return;
	while (!ft_check_newline(buffer))
	{
		free(buffer);
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return;
		reed = read(fd, buffer, BUFFER_SIZE);
		if (reed <= 0)
		{
			free(buffer);
			return;
		}
		*stock = ft_strjoin(*stock, buffer);
	}
	free(buffer);
}

char *ft_get_line(char *stock, char *line)
{
	int i;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i]== '\n')
		i++;
	free(line);
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while(stock[i]!= '\n' && stock[i]!= '\0')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i]== '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *ft_clean_stock(char *stock)
{
	int i;
	char *new_stock;
	int j;
	
	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i]== '\n')
		i++;
	j = 0;
	while (stock[i + j])
		j++;
	new_stock = ft_calloc(sizeof(char), (j + 1));
	if (!new_stock)
		return (NULL);
	j = 0;
	while (stock[i + j])
	{
		new_stock[j] = stock[i + j];
		j++;
	}
	free(stock);
	new_stock[j] = '\0';
	return (new_stock);
}