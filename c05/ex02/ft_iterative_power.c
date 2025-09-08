int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	tmp;

	result = 1;
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	printf("%d,",ft_iterative_power(2,2));
	printf("%d,",ft_iterative_power(2,3));
	printf("%d,",ft_iterative_power(2,4));
	printf("%d,",ft_iterative_power(2,5));

}