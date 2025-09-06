char *ft_strupcase(char *str)
{
	char *orig = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			(*str) -= 32;
		}
		str++;
	}
	return orig;	
}

#include <stdio.h>

char    *ft_strupcase(char *str);

int main(void)
{
    char test1[] = "hello world!";
    char test2[] = "42tokyoPiscine";
    char test3[] = "ALREADY UPPER";
    char test4[] = "mIxEd CaSe";
    char test5[] = "";

    printf("before: %s\n", test1);
    printf("after : %s\n\n", ft_strupcase(test1));

    printf("before: %s\n", test2);
    printf("after : %s\n\n", ft_strupcase(test2));

    printf("before: %s\n", test3);
    printf("after : %s\n\n", ft_strupcase(test3));

    printf("before: %s\n", test4);
    printf("after : %s\n\n", ft_strupcase(test4));

    printf("before: \"%s\"\n", test5);
    printf("after : \"%s\"\n\n", ft_strupcase(test5));

    return 0;
}
