int	word_check(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	if (c >= '0' && c <= '9')
		return (3);
	return (0);
}

char *ft_strcapitalize(char *str)
{
	char *orig;
	int	is_word;

	orig = str;
	is_word = 1;
	while (*str)
	{
		if (word_check(*str))
		{
			if (word_check(*str) == 2 && is_word == 1)
			{
				*str -= 32;
				is_word = 0;
			}
			else if (word_check(*str) == 1 && is_word == 0)
					*str += 32;
			is_word = 0;
		}
		else
			is_word = 1;
		str++;
	}
		return (orig);
}

#include <stdio.h>
int main(void)
{
    char test1[] = "hi, how are you? 42words forty-two; fifty+and+one";
    printf("before: %s\n", test1);
    printf("after : %s\n\n", ft_strcapitalize(test1));

    char test2[] = "HELLO wOrLd! 123abc TEST-case";
    printf("before: %s\n", test2);
    printf("after : %s\n\n", ft_strcapitalize(test2));

    return 0;
}
