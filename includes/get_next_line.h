#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
int	ft_strlen(char *str);
char			*ft_strdup(char *s);
char			*ft_strjoin(char *s1, char *s2);

#endif
