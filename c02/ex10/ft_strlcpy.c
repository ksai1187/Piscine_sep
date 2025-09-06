unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i = 0;
	int	len = 0;

	while (src[len])
		len++;	
	if(size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (len);
	
}