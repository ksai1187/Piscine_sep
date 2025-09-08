

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
int ft_atoi_base(char *str, char *base)
{
	
	
	
	
}