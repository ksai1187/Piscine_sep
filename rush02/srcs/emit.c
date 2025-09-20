#include "rush02.h"

int	emit_chunk_with_scale(t_emit *e, const char *buf, int rem)
{
	char	*scale;

	if (is_all_zero(buf))
		return (1);
	print_below_1000(e, buf);
	if (e->dict_error)
		return (0);
	if (rem <= 0)
		return (1);
	scale = make_scale_key(rem * 3);
	if (!scale)
		return (0);
	emit_dict_word(e, scale);
	free(scale);
	return (e->dict_error == 0);
}

int	process_head(const char *num, size_t head, t_emit *e, int *rem)
{
	char	buf[4];
	size_t	k;

	k = 0;
	while (k < head)
	{
		buf[k] = num[k];
		k++;
	}
	buf[k] = '\0';
	if (!emit_chunk_with_scale(e, buf, *rem))
		return (0);
	return (1);
}

int	process_tail(const char *num, size_t i, size_t len, t_emit *e, int rem)
{
	char	buf[4];

	while (i < len)
	{
		rem--;
		buf[0] = num[i];
		buf[1] = num[i + 1];
		buf[2] = num[i + 2];
		buf[3] = '\0';
		if (!emit_chunk_with_scale(e, buf, rem))
			return (0);
		i += 3;
	}
	return (1);
}

int	slice_and_emit(t_emit *e, const char *num)
{
	size_t	len;
	size_t	head;
	size_t	i;
	int		rem;

	len = str_len(num);
	head = len % 3;
	if (head == 0)
		head = 3;
	rem = (int)((len - head) / 3);
	if (!process_head(num, head, e, &rem))
		return (0);
	i = head;
	return (process_tail(num, i, len, e, rem));
}
