
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 #include <fcntl.h>

char	*get_next_line(int fd)
{
	int		index;
	int		bytes;
	char	*buffer;
	char	character;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	index = 0;
	bytes = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	buffer = (100000);
	while (bytes > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, BUFFER_SIZE -  BUFFER_SIZE + 1);
	}
	if ((bytes <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}