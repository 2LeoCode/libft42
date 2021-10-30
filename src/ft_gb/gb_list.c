/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:38:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 22:00:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <listft.h>

void	gb_list_destroy(t_list *lst, t_freef *free_fun)
{
	lst_destroy(lst, free_fun);
	ft_free(lst);
}

t_list	*gb_list_new(t_list *addr, t_freef *free_fun)
{
	t_list	*ptr;

	ptr = ft_malloc(sizeof(t_list));
	if (!ptr)
	{
		gb_clear();
		return (NULL);
	}
	list_init(ptr);
	if (gb_main(ptr, free_fun, gbop_push, true) == GB_FAILURE)
		return (NULL);
	return (ptr);
}
