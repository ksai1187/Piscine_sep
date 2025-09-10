#include <unistd.h>

int	ft_strcmp(char *s1,char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
		return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
	write(1, "\n", 1);
	
}
int	main(int ac,char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < ac - 1)
	{
		j = 1;
		while (j < ac - 1)
		{
			if(ft_strcmp(av[j],av[j + 1]) > 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < ac)
		ft_putstr(av[i++]);
}
