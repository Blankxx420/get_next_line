/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:54 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/19 12:33:43 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_found_newline(t_list *stash)
{
	int i;
	t_list *current;
	
	i = 0;
	if (stash == NULL)
		return(0);
	current = ft_get_lst_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

t_list	*ft_get_lst_last(t_list *stash)
{
	while (stash && stash->next)
		stash = stash->next;
	return (stash)
}