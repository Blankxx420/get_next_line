/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:30:54 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/16 15:51:19 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		file;
	file = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(file));	
	close(file);
}