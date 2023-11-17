/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:30:54 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:00 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		file;
	char	*str;
	file = open("test.txt", O_RDONLY);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	close(file);
}