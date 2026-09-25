#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd1;
    char *line;

    fd1 = open("big_test.txt", O_RDONLY);
    if (fd1 < 0)
        return (1);
		
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd1);
    return (0);
}
