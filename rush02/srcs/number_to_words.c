#include "rush02.h"

int	number_to_words(const char *num, t_stock_str *tab)
{
	t_emit	e;
	const char	*nrm;
	const char	*w0;

	e.first_done = 0;
	e.dict_error = 0;
	e.tab = tab;

	if (!num || !*num)
	{
		put_s("Dict Error\n");
		return (0);
	}
	nrm = skip_leading_zeros(num);
	if (nrm[0] == '0')
	{
		w0 = dict_get(tab, "0");
		if (!w0)
		{
			put_s("Dict Error\n");
			return (0);
		}
		put_s(w0);
		put_c('\n');
		return (1);
	}
	if (!slice_and_emit(&e, nrm) || e.dict_error)
	{
		put_s("Dict Error\n");
		return (0);
	}
	put_c('\n');
	return (1);
}
