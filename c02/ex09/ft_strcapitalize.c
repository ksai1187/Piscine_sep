char *ft_strcapitalize(char *str)
{
	char *orig;
	int	is_word;

	orig = str;
	is_word = 1;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Z' ) || (*str >= 'a' &&  *str <= 'z') || (*str >= '0' && *str <= '9'))
		{
			if (is_word == 1)
			{
				if (*str >= 'a' && *str <= 'z')
					*str -= 32;
				is_word = 0;
			}
			else
			{
				if (*str >= 'A' && *str <= 'Z')
					*str += 32;
			}
		}
		else
		{
			is_word = 1;
		}
		str++;
	}
		return (orig);
		
}

#include <stdio.h>
int main(void)
{
    // テストケース 1
    char test1[] = "hi, how are you? 42words forty-two; fifty+and+one";
    printf("before: %s\n", test1);
    printf("after : %s\n\n", ft_strcapitalize(test1));

    // テストケース 2
    char test2[] = "HELLO wOrLd! 123abc TEST-case";
    printf("before: %s\n", test2);
    printf("after : %s\n\n", ft_strcapitalize(test2));

    return 0;
}
