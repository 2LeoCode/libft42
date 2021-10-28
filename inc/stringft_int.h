/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:18:20 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/14 14:37:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGFT_INT_H
# define STRINGFT_INT_H

# include <stddef.h>

typedef struct s_string {
	char	*begin;
	char	*end;
	size_t	length;
	size_t	capacity;
	char	data[];
}	t_string;

#endif
