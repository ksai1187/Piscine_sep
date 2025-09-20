/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42tokyo.jp>  +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/09/21 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stock_str
{
	char		*key;
	char		*val;
}				t_stock_str;

typedef struct s_emit
{
	int			first_done;
	int			dict_error;
	t_stock_str	*tab;
}				t_emit;

/* string / io */
size_t			str_len(const char *s);
int				str_cmp(const char *a, const char *b);
void			put_n(const char *s, size_t n);
void			put_s(const char *s);
void			put_c(char c);

/* numeric helpers */
int				is_all_zero(const char *s);
const char		*skip_leading_zeros(const char *num);
char			*make_scale_key(int zeros);

/* dict / emit */
const char		*dict_get(t_stock_str *tab, const char *key);
void			emit_word(t_emit *e, const char *w);
void			emit_dict_word(t_emit *e, const char *key);

/* <1000 */
void			three_digits_pack(char out[3], const char *chunk);
void			three_digits_hundreds(t_emit *e, const char d[3]);
void			three_digits_tens_ones(t_emit *e, const char d[3]);
void			print_below_1000(t_emit *e, const char *chunk);

/* slicing */
int				emit_chunk_with_scale(t_emit *e, const char *buf, int rem);
int				process_head(const char *num, size_t head, t_emit *e, int *rem);
int				process_tail(const char *num, size_t i, size_t len, t_emit *e,
					int rem);
int				slice_and_emit(t_emit *e, const char *num);

/* api */
int				number_to_words(const char *num, t_stock_str *tab);
int				count_word(char *str, char *charset);
int				is_sep(char *charset,char c);
char			*malloc_word(char *str,char *charset);
char			**ft_split(char *str, char *charset);
t_stock_str		*ft_strs_to_tab(int size, char **spl);
char			*ft_strtrim_ws( char *s);
int				ft_strlen( char *s);
int				is_space(char c);


#endif
