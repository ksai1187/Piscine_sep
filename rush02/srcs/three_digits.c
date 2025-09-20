#include "rush02.h"

void	three_digits_pack(char out[3], const char *chunk)
{
	size_t	l;

	out[0] = '0';
	out[1] = '0';
	out[2] = '0';
	l = str_len(chunk);
	if (l == 1)
		out[2] = chunk[0];
	else if (l == 2)
	{
		out[1] = chunk[0];
		out[2] = chunk[1];
	}
	else
	{
		out[0] = chunk[0];
		out[1] = chunk[1];
		out[2] = chunk[2];
	}
}

void	three_digits_hundreds(t_emit *e, const char d[3])
{
	char	k1[2];

	if (d[0] == '0')
		return ;
	k1[0] = d[0];
	k1[1] = '\0';
	emit_dict_word(e, k1);
	if (!e->dict_error)
		emit_dict_word(e, "100");
}

void	three_digits_tens_ones(t_emit *e, const char d[3])
{
	char	k2[3];
	char	kt[3];
	char	ko[2];

	if (d[1] == '0' && d[2] == '0')
		return ;
	if (d[1] == '1')
	{
		k2[0] = d[1];
		k2[1] = d[2];
		k2[2] = '\0';
		emit_dict_word(e, k2);
		return ;
	}
	if (d[1] != '0')
	{
		kt[0] = d[1];
		kt[1] = '0';
		kt[2] = '\0';
		emit_dict_word(e, kt);
	}
	if (d[2] != '0')
	{
		ko[0] = d[2];
		ko[1] = '\0';
		emit_dict_word(e, ko);
	}
}

void	print_below_1000(t_emit *e, const char *chunk)
{
	char	d[3];

	three_digits_pack(d, chunk);
	three_digits_hundreds(e, d);
	if (!e->dict_error)
		three_digits_tens_ones(e, d);
}
