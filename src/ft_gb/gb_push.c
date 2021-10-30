/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:15 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 21:29:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>

short	gb_push(void *data, t_freef *free_fun)
{
	return (gb_main(data, free_fun, gbop_push, false));
}
