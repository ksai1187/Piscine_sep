#include <unistd.h>


int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if(base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	print_num(long nbr,char *base,int base_len)
{
	char	c;
	if (nbr >= base_len)
	{
		put_num((nbr / base_len),base,base_len);
	}
	c = base[nbr % base_len];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;

	if(!(base_len = check_base(base)))
		return ;
	
	n = (long)nbr;
	if(nbr < 0)
	{
		write(1, "-", 1);
		n = -nbr;
	}
	put_num(n,base,base_len);
	
	
}

int	main(void)
{
	ft_putnbr_base(-255,"0123456789abcdef");
	
	
	
	
}