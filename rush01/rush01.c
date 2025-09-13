#include <unistd.h>

int		issp(char c)
{
	return (c == ' ' || c == '\t');
}

void	push_buf(int *v, int up[4], int dn[4], int lf[4], int rt[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		up[i] = v[i];
		dn[i] = v[4 + i];
		lf[i] = v[8 + i];
		rt[i] = v[12 + i];
		i++;
	}
}
int		parse(char *in, int up[4], int dn[4], int lf[4], int rt[4])
{
	int v[16];
	int k;

	k = 0;
	while (*in)
	{
		if (issp(*in))
			in++;
		else if (*in >= '1' && *in <= '4')
		{
			if (k == 16)
				return (0);
			v[k++] = *in - '0';
			in++;
		}
		else
			return (0);
	}
	if (k != 16)
		return (0);
	push_buf(v, up, dn, lf, rt);
	return (1);
}


int	vis4(int a, int b, int c, int d)
{
	int m = 0;
	int cnt = 0;

	if (a > m) 
	{
		 m = a; 
		 cnt++; 
	}
	if (b > m) 
	{	
		 m = b;
		cnt++;
	}
	if (c > m) 
	{ 
		m = c;
		cnt++;
	}
	if (d > m) 
	{ 
		m = d;
		cnt++; 
	}
	return (cnt);
}

int	row_check(int g[4][4], int row, int lf, int rt)
{
	int	a;
	int	b;
	int	c;
	int	d;
	
	a = g[row][0];
	b = g[row][1];
	c = g[row][2];
	d = g[row][3];

	return (vis4(a, b, c, d) == lf && vis4(d, c, b, a) == rt);
}

int	col_check(int g[4][4], int col, int up, int dn)
{
	int	a;
	int	b;
	int	c;
	int	d;
	
	a = g[0][col];
	b = g[1][col];
	c = g[2][col];
	d = g[3][col];
	return (vis4(a, b, c, d) == up && vis4(d, c, b, a) == dn);
}

int	checke_rc(int g[4][4], int row, int col, int v)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g[row][i] == v || g[i][col] == v)
			return (0);
		i++;
	}
	return (1);
}


void	put1(int n)
{
	char d = '0' + n;
	write(1, &d, 1);
}


void	print(int g[4][4])
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (col)
				write(1, " ", 1);
			put1(g[row][col]);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	back_tracking(int pos, int g[4][4], int up[4], int dn[4], int lf[4], int rt[4])
{
	int row;
	int col;
	int v;
	int check;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	v = 1;
	while (v <= 4)
	{
		if (checke_rc(g, row, col, v))
		{
			g[row][col] = v;
			if ((col == 3 && !row_check(g, row, lf[row], rt[row]))
			|| (row == 3 && !col_check(g, col, up[col], dn[col]))
			|| !back_tracking(pos + 1, g, up, dn, lf, rt))
				g[row][col] = 0;
			else
			return (1);
		}
		v++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int up[4], dn[4], lf[4], rt[4];
	int g[4][4];
	int r, c;

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
			g[r][c++] = 0;
		r++;
	}
	if (!parse(av[1], up, dn, lf, rt) || !back_tracking(0, g, up, dn, lf, rt))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print(g);
	return (0);
}
