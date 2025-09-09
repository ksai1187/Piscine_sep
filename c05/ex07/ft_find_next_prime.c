int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);	
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;	
	}
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n",ft_find_next_prime(2147483647));
	printf("%d\n",ft_find_next_prime(2147483630));
	printf("%d\n",ft_find_next_prime(2147483600));
}