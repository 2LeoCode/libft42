/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:19:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:40:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>

int	gbop_clear(t_list *gb, void *data, t_freef *free_fun)
{
	t_node	*tmp;
	t_node	*ptr;
	t_pair	*elem_ptr;

	ptr = gb->next;
	while (ptr != gb)
	{
		elem_ptr = ptr->data;
		if (elem_ptr->second)
			((t_freef *)elem_ptr->second)(elem_ptr->first);
		ft_free(elem_ptr);
		tmp = ptr->next;
		ft_free(ptr);
		ptr = tmp;
	}
	gb->data = NULL;
	gb->next = gb;
	gb->prev = gb;
	if (free_fun)
		free_fun(data);
	return (GB_SUCCESS);
}

int	gbop_push(t_list *gb, void *data, t_freef *free_fun)
{
	t_pair	*elem;

	elem = make_pair(data, free_fun);
	if (elem && !list_push_front(gb, elem))
		return (GB_SUCCESS);
	gbop_clear(gb, data, free_fun);
	return (GB_FAILURE);
}

int	gbop_pop(t_list *gb, void *data, t_freef *free_fun)
{
	t_pair	*ptr;

	(void)data;
	(void)free_fun;
	ptr = list_pop_front(gb);
	if (ptr)
	{
		if (ptr->second)
			((t_freef *)ptr->second)(ptr->first);
		ft_free(ptr);
	}
	return (GB_SUCCESS);
}

int	gb_main(void *data, t_freef *free_fun, t_gbop *op)
{
	static t_list	garbage = {0, (t_node *)&garbage, (t_node *)&garbage};

	return (op(&garbage, data, free_fun));
}
