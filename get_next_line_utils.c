/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:54 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/17 14:43:50 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *dest, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < size)
	{
		*((unsigned char *) dest + index) = '\0';
		index++;
	}
}

void	*ft_calloc(size_t elementcount, size_t elementcize)
{
	void	*tab;

	if (elementcize == 0 || elementcount == 0)
	{
		tab = malloc(1);
		if (tab == NULL)
			return (NULL);
		ft_bzero(tab, 1);
		return (tab);
	}
	if (elementcount * elementcize / elementcize != elementcount)
		return (NULL);
	tab = malloc(elementcize * elementcount);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, elementcount * elementcize);
	return (tab);
}

int	ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
	{
		dest = ft_calloc(1, sizeof(char));
		if (dest == NULL)
			return (NULL);
		return (dest);
	}
	if (len + start > size)
		len = size - start;
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, (char *)s + start, len);
	return (dest);
}

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *) destination;
	src = (unsigned char *) source;
	index = 0;
	if (source == NULL && destination == NULL && size != 0)
		return (destination);
	while (index < size)
	{
		dest[index] = src[index];
		index++;
	}
	return (destination);
}