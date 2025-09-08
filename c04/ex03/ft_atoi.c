int	is_space(char c)
{
	char *space = " \t\v\f\n\r";
	while (*space)
	{
		if (c == *space)
			return (1);
		space++;
	}
	return (0);
}

int	check_sign(char **str)
{
	int	cnt;

	cnt = 0;
	while (**str == '+' || **str == '-')
	{
		if(**str == '-')
			cnt++;
		(*str)++;
	}
	if (cnt % 2 == 1)
		return -1;
	return 1;
}
int ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	while (is_space(*str))
		str++;
	sign = check_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return sign * result;
}
#include <stdio.h>

int	main(void)
{
	printf("%d",ft_atoi("    ---11111"));
	
	
	
	
}
