/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_find_first_of.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:01:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:24:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_find_first_of(const t_string *s, const char *pattern)
{
	const size_t	pat_len = ft_strlen(pattern);
	const char		*ptr = s->begin;

	while (ptr != s->end && !ft_memchr(pattern, *ptr, pat_len))
		++ptr;
	if (ptr == s->end)
		ptr = NULL;
	return ((char *)ptr);
}
