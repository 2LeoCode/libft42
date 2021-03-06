/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:03:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 15:07:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>

char	string_front(const t_string *s)
{
	return (!!s->length * s->data[0]);
}
