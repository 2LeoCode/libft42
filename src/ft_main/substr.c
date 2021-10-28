/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:36:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:35:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			start_c;

	start_c = 0;
	if (s_len >= start)
		start_c = s[start];
	while (*s && *s != start_c)
		++s;
	return (ft_strndup(s, ft_strnlen(s, len)));
}
