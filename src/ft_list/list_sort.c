/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:53:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:23:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <stddef.h>
#include <libft.h>
#include <libft_types.h>

static int	compare(void *a, void *b, t_cmpf cmp_fun, void *cmp_param)
{
	if (cmp_param)
		return (cmp_fun(a, b, cmp_param));
	return (cmp_fun(a, b));
}

static t_pair	get_extremes(t_node *front, t_node *back, t_cmpf cmp_fun,
					void *cmp_param)
{
	t_node	*ptr;
	void	*max;
	void	*min;

	max = back->data;
	min = front->data;
	ptr = front->next;
	while (ptr != back)
	{
		if (compare(min, ptr->data, cmp_fun, cmp_param) > 0)
			min = ptr->data;
		else if (compare(max, ptr->data, cmp_fun, cmp_param) < 0)
			max = ptr->data;
	}
	return ((t_pair){min, max});
}

void	list_sort(t_list *lst, t_cmpf *cmp_fun, void *cmp_param)
{
	t_node	*front;
	t_node	*back;
	t_pair	extremes;

	front = lst->next;
	back = lst->prev;
	while (front != back)
	{
		if (compare(front->data, back->data, cmp_fun, cmp_param) > 0)
			ft_swap(&extremes.first, &extremes.second, sizeof(void *));
		extremes = get_extremes(front, back, cmp_fun, cmp_param);
		if (extremes.first != front->data)
			ft_swap(&extremes.first, &front->data, sizeof(void *));
		if (extremes.second != back->data)
			ft_swap(&extremes.second, &back->data, sizeof(void *));
		if (front->next != back)
			front = front->next;
		back = back->prev;
	}
}
