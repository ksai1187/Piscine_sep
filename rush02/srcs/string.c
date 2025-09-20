#include <stdlib.h>

int		is_sep(char *charset,char c)
{
	while (*charset)
	{
		if (*charset == c)
		{
			return (1);
		}
		charset++;
	}
	return 0;
}

int		count_word(char *str,char *charset)
{
	int		is_word;
	int		len;

	is_word = 0;
	len = 0;
	while (*str)
	{
		if (is_sep(charset,*str))
			is_word = 0;
		else if(!is_word)
		{
			len++;
			is_word = 1;
		}
		str++;
	}
	return (len);
}
char	*malloc_word(char *str,char *charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] && !is_sep(charset,str[len]))
		len++;
	word = malloc(len + 1);
	if(!word)
		return NULL;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}
char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_len;
	char	**newarr;

	word_len = count_word(str,charset);
	newarr = malloc(sizeof(char *) * (word_len + 1));
	if(!newarr)
		return NULL;
	i = 0;
	while (*str)
	{
		if (!is_sep(charset,*str))
		{
			newarr[i] = malloc_word(str,charset);
			if(!newarr[i])
				return (NULL);
			i++;
			while (!is_sep(charset,*str) && *str)
				str++;			
		}
		else
			str++;
	}
	newarr[word_len] = NULL;
	return (newarr);	
}



