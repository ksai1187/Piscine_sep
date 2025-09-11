#include <stdlib.h>
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr,char *base);
int		check_base(char *base);


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!check_base(base_from)|| !check_base(base_to))
		return NULL;
	return ((ft_itoa_base(ft_atoi_base(nbr,base_from),base_to)));
}

#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_convert_base("-2147483648","0123456789","0"));
	printf("%s\n",ft_convert_base("-2147483648","0123456789","01234567"));
	printf("%s\n",ft_convert_base("-2147483648","0123456789","0123456789"));
	printf("%s\n",ft_convert_base("-2147483648","0123456789",""));
	
	
	
	
}