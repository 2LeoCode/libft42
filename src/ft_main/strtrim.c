/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:56:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(const char *s, const char *set)
{
	char	*ptr;
	size_t	len;

	while (*s && ft_strchr(set, *s))
		++s;
	len = ft_strlen(s);
	while (len && ft_strchr(set, s[len - 1]))
		--len;
	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
		*ft_stpncpy(ptr, s, len) = 0;
	return (ptr);
}
