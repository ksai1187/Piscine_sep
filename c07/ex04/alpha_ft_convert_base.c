#include <stdlib.h>

int		check_sign(char **str);
int		check_base(char *base);
int		count_len(long long nbr,char *base);
int		base_index(char *base,char c);
int		ft_strlen(char *str);

int	is_space(char c)
{
	char *space = " \t\v\r\n\f"; 
	while (*space)
	{
		if (*space == c)
		{
			return 1;
		}
		space++;
	}
	return 0;
}

int ft_atoi_base(char *str, char *base)
{
	int sign;
	int	result;
	int	n;
	int	base_len;
	
	base_len = check_base(base);
	if (!base_len)
		return 0;
	while (is_space(*str))
		str++;
	sign = check_sign(&str);
	result = 0;
	while (*str)
	{
		n = base_index(base,*str);
		if (n == -1 || n >= base_len)
			break;
		result = result * base_len + n;
		str++;
	}
	return (sign * result);
}

char	*ft_itoa_base(int nbr,char *base)
{
	char		*num_str;
	int			total_len;
	int			base_len;
	long long	n;
	
	n = nbr;
	total_len = count_len(n,base);
	num_str = malloc(sizeof(char) * (total_len + 1));
	base_len = ft_strlen(base);
	num_str[total_len] = '\0';
	if (n == 0)
		num_str[0] = '0';
	if (n < 0)
	{
		num_str[0] = '-';
		n = -n;
	}
	while (n)
	{
		num_str[--total_len] = base[n % base_len];
		n /= base_len;
	}
	return (num_str);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!check_base(base_from)|| !check_base(base_to))
		return NULL;
	return ((ft_itoa_base(ft_atoi_base(nbr,base_from),base_to)));
}

//#include <stdio.h>
//int	main(void)
//{
//	printf("%s\n",ft_convert_base("-2147483648","0123456789","0"));
//	printf("%s\n",ft_convert_base("-2147483648","0123456789","01234567"));
//	printf("%s\n",ft_convert_base("-2147483648","0123456789","0123456789"));
//	printf("%s\n",ft_convert_base("-2147483648","0123456789",""));
//}