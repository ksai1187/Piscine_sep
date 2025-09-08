int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if(nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);	
}

//#include <stdio.h>

//int	main(void)
//{
//	printf("%d,%d",ft_iterative_factorial(2),ft_iterative_factorial(3));
//}