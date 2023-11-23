/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:30:54 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/23 14:08:55 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		file;
	file = open("test.txt", O_RDONLY);
	char *line;
	for (int i = 0; i < 25; i++)
	{
		line = get_next_line(file);
		printf("%s", line);
		free(line);
	}
	close(file);
	return (0);
}