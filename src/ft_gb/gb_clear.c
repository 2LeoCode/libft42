/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:31:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/09 16:08:24 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>

void	gb_clear(void)
{
	gb_main(NULL, NULL, (t_gbop *)gbop_clear, false);
}
