#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef B_SIZE
#  define B_SIZE 42
# endif

char	*get_next_line(int fd);

#endif