
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rush02.h"

# define BUF_SIZE 1024

int	main(int ac, char **av)
{
	int			fd;
	int			rc;
	int			len;
	char		buf[BUF_SIZE + 1];
	char		**spl1;
	t_stock_str	*tab;

	if (ac == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (ac == 3)
		fd = open(av[1], O_RDONLY);
	else
		return write(1, "Error\n", 6);
	if (fd == -1)
		return (write(1, "Dict Error\n", 11), 1);
	rc = read(fd, buf, BUF_SIZE);
	if (rc <= 0)
		return (write(1, "Dict Error\n", 11), 1);
	buf[rc] = '\0';
	spl1 = ft_split(buf, "\n");
	len = 0;
	while (spl1[len])
		len++;
	tab = ft_strs_to_tab(len, spl1);
	number_to_words(av[2], tab);
	close(fd);
	return (0);
}
