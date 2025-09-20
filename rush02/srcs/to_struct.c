#include "rush02.h"
#include <stdlib.h>



///* 空白判定（スペースやタブなど） *
 int is_space(char c)
{
    return (c == ' ' );
}

/* 文字列の長さ */

int ft_strlen( char *s)
{
    int  i = 0;
    while (s && s[i])
        i++;
    return i;
}

/* 前後の空白を削除した新しい文字列を返す */

char *ft_strtrim_ws( char *s)
{
    int start = 0;
    int  end;
    char *res;
    int  i;

    if (!s)
        return NULL;
    end = ft_strlen(s);
    if (end == 0)
        return NULL;

    /* 前から空白をスキップ */
    while (s[start] && is_space(s[start]))
        start++;

    /* 後ろから空白をスキップ */
    while (end > start && is_space(s[end - 1]))
        end--;

    /* 空白しかなかった場合 */
    if (start == end)
    {
        res = malloc(1);
        if (res)
            res[0] = '\0';
        return res;
    }

    /* 新しい文字列を確保 */
    res = malloc(end - start + 1);
    if (!res)
        return NULL;

    i = 0;
    while (start < end)
        res[i++] = s[start++];
    res[i] = '\0';

    return res;
}

t_stock_str *ft_strs_to_tab(int size, char **spl)
{
    t_stock_str *tab;
    int i;

    tab = malloc(sizeof(t_stock_str) * (size + 1));
    if (!tab)
        return (NULL);
    i = 0;
    while (i < size)
    {
        tab[i].key = ft_strtrim_ws(ft_split(spl[i],": ")[0]);
        tab[i].val = ft_strtrim_ws(ft_split(spl[i],":")[1]);
        if (!tab[i].val)
            return (NULL); 
        i++;
    }
    tab[i].val = 0;
	tab[i].key = 0; 
    return (tab);
}
