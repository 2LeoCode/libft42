/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:55:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:29:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_rfind(const t_string *s, const char *sequence)
{
	const size_t	seq_len = ft_strlen(sequence);
	const char		*ptr = s->end;

	while (--ptr >= (s->begin + seq_len)
		&& (*ptr != sequence[seq_len - 1]
		|| ft_memcmp(ptr - seq_len, sequence, seq_len)))
		continue ;
	if (ptr < s->begin + seq_len)
		ptr = NULL;
	return ((char *)ptr - seq_len);
}
