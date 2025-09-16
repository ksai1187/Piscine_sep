#include <stdlib.h>
#include <unistd.h>


typedef struct s_stock_str
{
    int size;   // 文字列の長さ
    char *str;  // 文字列へのポインタ
    char *copy; // 文字列のコピー
} t_stock_str;

void	print_num(long long nbr)
{
	char	c;
	if (nbr >= 10)
	{
		print_num(nbr / 10);
	}
	c = nbr % 10;
	write(1, &c, 1);
}

void	ft_putnum(int nbr)
{
	long long	n;

	n = nbr;
	if(nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	print_num(n);
}

void	put_str(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
	
	
}
int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

char *ft_strdup(char *src)
{
    int len;
    int i;
    char *dup;

    len = ft_strlen(src);
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *tab;
    int i;

    tab = malloc(sizeof(t_stock_str) * (ac + 1));
    if (!tab)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        tab[i].size = ft_strlen(av[i]);
        tab[i].str = av[i];
        tab[i].copy = ft_strdup(av[i]); // コピーを作成
        if (!tab[i].copy)
            return (NULL); // エラー処理
        i++;
    }
    tab[i].str = 0; // 終端
    return (tab);
}

void ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		put_str(par[i].str);
		write(1, "\n", 1);
		ft_putnum(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
int main(int ac,char **av)
{
	ft_show_tab(ft_strs_to_tab(ac,av));
	
	
}