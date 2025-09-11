#include <stdlib.h>

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

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if(!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
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

int	base_index(char *base,char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;	
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

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}
int		count_len(long long nbr,char *base)
{
	int	len;
	int	base_len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr = -nbr;
	}
	base_len = ft_strlen(base);
	while (nbr)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
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
