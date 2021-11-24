#ifndef SOO_LOONG_H
# define SOO_LOONG_H
#endif
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_fill_line(char **str, char *line);
char	*get_next_line(int fd);
int		ft_check(const char *str);
int		ft_read(int *ret, int fd, char **buff);

#endif
