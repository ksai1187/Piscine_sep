#include <unistd.h>


void	push_arr(char *ln, int buf[16], int up[4], int dn[4], int lf[4], int rt[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		up[i] = buf[i];
		dn[i] = buf[i + 4];
		lf[i] = buf[i + 8];
		rt[i] = buf[i + 12];
		i++;
	}
}
int		ft_atoi(char *in, int up[4], int dn[4], int lf[4], int rt[4])
{
	int	buf[16];
	int	i;

	i = 0;
	while (*in)
	{
		if (*in == ' ')
			in++;
		else if (*in >= '1' && *in <= '4')
		{
			if (i == 16)
				return (0);			
			buf[i] = *in - '0';
			i++;
			in++;
		}
		else
			return (0);
	}
	if (i != 16)
		return (0);
	push_buf(in,buf,up,dn,lf,rt);
	return (1);
	}
	
	int	back_tracking(int pos, int g[4][4], int up[4], int dn[4], int lf[4], int rt[4])
	{
		
		
		
		
		
		
	}
	
	







