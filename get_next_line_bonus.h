#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

void	ft_bzero(void *dest, unsigned int size);
void	*ft_calloc(size_t elementcount, size_t elementcize);
void    ft_read_and_extract(int fd, char **stock);
int     ft_check_newline(char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char 	*ft_get_line(char *buffer, char *line);
char	*ft_strdup(char *s);
char 	*ft_clean_stock(char *stock);

#endif
