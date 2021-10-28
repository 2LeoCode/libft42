/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbft_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:27:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:39:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GBFT_INT_H
# define GBFT_INT_H

# include "gbft.h"
# include "listft.h"

typedef int	t_gbop();

int	gb_main(void *data, t_freef *free_fun, t_gbop *op);
int	gbop_clear(t_list *gb, void *data, t_freef *free_fun);
int	gbop_push(t_list *gb, void *data, t_freef *free_fun);
int	gbop_pop(t_list *gb, void *data, t_freef *free_fun);

#endif
