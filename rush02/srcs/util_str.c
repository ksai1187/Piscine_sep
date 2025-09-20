#include "rush02.h"

size_t	str_len(const char *s)
{
	size_t	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}

int	str_cmp(const char *a, const char *b)
{
	size_t	i;

	if (!a || !b)
		return (a != b);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

void	put_n(const char *s, size_t n)
{
	if (s && n)
		(void)!write(1, s, n);
}

void	put_s(const char *s)
{
	put_n(s, str_len(s));
}

void	put_c(char c)
{
	(void)!write(1, &c, 1);
}
