#include <stdlib.h>

int ft_strlen(char *src)
{
    int len = 0;
    while (src[len])
        len++;
    return (len);
}

int count_len(char **strs, int size, char *sep)
{
    int result = 0;
    int i = 0;

    while (i < size)
    {
        result += ft_strlen(strs[i]);
        i++;
    }
    if (size > 1)
        result += (ft_strlen(sep) * (size - 1));
    return (result);
}
char *ft_strcpy(char *res,char **strs,char *sep,int size)
{
	int   i;
	int   j;
	int   k;

	i = 0;
	j = 0;
	while (j < size)
    {
        k = 0;
        while (strs[j][k])
            res[i++] = strs[j][k++];
        if (j < size - 1)
        {
            k = 0;
            while (sep[k])
                res[i++] = sep[k++];
        }
		j++;
    }  
    res[i] = '\0';
	return (res);
}
char *ft_strjoin(int size, char **strs, char *sep)
{
    char *res;
    int   len;

    if (size <= 0)
    {
        res = (char *)malloc(1);
        if (!res)
            return NULL;
        res[0] = '\0';
        return res;
    }
    len = count_len(strs, size, sep);
    res = malloc((len + 1) * sizeof(char));
    if (!res)
        return NULL;
	res = ft_strcpy(res,strs,sep,size);
    return res;
}

#include <stdio.h>

int main(void)
{
    char *twodim[] = { "abcd", "efgh", "hijk" };
    char *sep = "@@";

    char *s = ft_strjoin(3, twodim, sep);
        printf("%s\n", s);
}
