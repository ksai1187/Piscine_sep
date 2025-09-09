int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n",ft_is_prime(3));
	printf("%d\n",ft_is_prime(6));
	printf("%d\n",ft_is_prime(37));

	
	
	
}