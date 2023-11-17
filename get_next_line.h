#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t elementcount, size_t elementcize);
void	ft_bzero(void *dest, unsigned int size);
void	*ft_memcpy(void *destination, const void *source, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
#endif
