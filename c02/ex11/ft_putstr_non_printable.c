#include <unistd.h>

void	print_hex(unsigned char c)
{
	char *hex = "0123456789abcdef";
	char buf[2];

	buf[0] = hex[c / 16];
	buf[1] = hex[c % 16];
	write(1, "\\",1);
	write(1, buf, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	while (*str)
	{
		c = (unsigned char)*str;
		if (c < 32 || c == 127)
			print_hex(c);
		else
			write(1, &c, 1);
		str++;
	}
}

#include <stdio.h>

int main(void)
{
    char test1[] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(test1);
    write(1, "\n", 1);

    char test2[] = "Hello\x07World";
    ft_putstr_non_printable("Hello\nHow are you?");
    write(1, "\n", 1);

    return 0;
}
