/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_find_last_of.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:05:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:26:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_find_last_of(const t_string *s, const char *pattern)
{
	const size_t	pat_len = ft_strlen(pattern);
	const char		*ptr = s->end;

	while (--ptr >= s->begin && !ft_memchr(pattern, *ptr, pat_len))
		continue ;
	if (ptr == s->begin + pat_len - 1)
		ptr = NULL;
	return ((char *)ptr);
}