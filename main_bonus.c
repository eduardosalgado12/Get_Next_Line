#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;


	fd1 = open("big_A.txt", O_RDONLY);
	fd2 = open("big_B.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0)
		return (1);

			line1 = get_next_line(fd1);
			if (line1)
			{
				printf("%s", line1);
				free(line1);
			}

			line2 = get_next_line(fd2);
			if (line2)
			{
				printf("%s", line2);
				free(line2);
			}
			line1 = get_next_line(fd1);
			if (line1)
			{
				printf("%s", line1);
				free(line1);

	}

	close(fd1);
	close(fd2);
	return (0);
}
