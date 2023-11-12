#include <unistd.h> // For read
#include <stdlib.h> // For malloc && free

// #define BUFFER_SIZE 8192

char	*get_next_line(int fd)
{
	int		index;
	int		bytes;
	char	*buffer;
	char	character;
	char 	*buffer2;
	int 	x;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || read(fd, NULL, 0) < 0)
		return (NULL);
	index = 0;
	bytes = read(fd, &character, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (bytes > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	buffer2 = (char *)malloc(sizeof(char) * (index));
	x = 0;
	while(x < index)
	{
		buffer2[x] = buffer[x];
		x++;
	}
	buffer2[x] = '\0';
	free(buffer);
	return (buffer2);
}



#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open("testread.txt", O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s", line, string);
			free(string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}



//gcc -Wall -Werror -Wextra train.c -D BUFFER_SIZE=10 && ./a.out train.c
