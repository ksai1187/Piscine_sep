int ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
		return (1);	
	return (nb * ft_recursive_power(nb, power - 1));
}


#include <stdio.h>

int	main(void)
{
	printf("%d,",ft_recursive_power(2,0));
	printf("%d,",ft_recursive_power(2,1));
	printf("%d,",ft_recursive_power(2,2));
	printf("%d,",ft_recursive_power(2,3));
	printf("%d,",ft_recursive_power(2,4));
	

	
	
}