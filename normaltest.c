/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normaltest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:19:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 21:12:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft.h>
#include <stringft.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char **argv) {
	t_string	*s1, *s2, *s3, *s4, *s5;

	if (gb_construct(&s1, (t_allocf *)string_from, "Hello", ft_free))
		return (-1);
	if (gb_construct(&s2, (t_allocf *)string_from, "World", ft_free))
		return (-1);
	if (gb_construct(&s3, (t_allocf *)string_from, "Fils de pute", ft_free))
		return (-1);
	if (gb_construct(&s4, (t_allocf *)string_from, "Gros encule", ft_free))
		return (-1);
	if (gb_construct(&s5, (t_allocf *)string_from, "Ta mere la chienne", ft_free))
		return (-1);
	string_putend(s1);
	string_putend(s2);
	string_putend(s3);
	string_putend(s4);
	string_putend(s5);
	gb_clear();
	return (0);
}
