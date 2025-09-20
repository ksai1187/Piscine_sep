#include "rush02.h"

const char	*dict_get(t_stock_str *tab, const char *key)
{
	int	i;

	if (!tab || !key)
		return (NULL);
	i = 0;
	while (tab[i].key || tab[i].val)
	{
		if (tab[i].key && tab[i].val && str_cmp(tab[i].key, key) == 0)
			return (tab[i].val);
		i++;
	}
	return (NULL);
}

void	emit_word(t_emit *e, const char *w)
{
	if (e->dict_error || !w || !*w)
		return ;
	if (e->first_done)
		put_c(' ');
	put_s(w);
	e->first_done = 1;
}

void	emit_dict_word(t_emit *e, const char *key)
{
	const char	*w;

	w = dict_get(e->tab, key);
	if (!w)
	{
		e->dict_error = 1;
		return ;
	}
	emit_word(e, w);
}
