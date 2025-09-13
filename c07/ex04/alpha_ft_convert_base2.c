#include <stdlib.h>
int	is_space(char c);

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

