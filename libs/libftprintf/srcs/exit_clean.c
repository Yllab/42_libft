/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:00:29 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 17:16:33 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				exit_clean(char **ret, t_index *params)
{
	if (ret && params->buf && !params->error)
		*ret = params->buf;
	if (params->error && params->buf)
		ft_memdel((void**)&(params->buf));
	if (!params->error)
		return (params->head);
	else
		return (-1);
}
