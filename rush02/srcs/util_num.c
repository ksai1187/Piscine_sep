#include "rush02.h"

int	is_all_zero(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

const char	*skip_leading_zeros(const char *num)
{
	while (*num == '0')
		num++;
	if (*num)
		return (num);
	return ("0");
}

char	*make_scale_key(int zeros)
{
	char	*s;
	int		i;

	if (zeros <= 0)
		return (NULL);
	s = (char *)malloc((size_t)zeros + 2);
	if (!s)
		return (NULL);
	s[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		s[i] = '0';
		i++;
	}
	s[zeros + 1] = '\0';
	return (s);
}
