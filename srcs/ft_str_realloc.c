/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:15:59 by hbally            #+#    #+#             */
/*   Updated: 2018/12/29 19:27:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_str_realloc(char *old, size_t size)
{
	unsigned int	i;
	char			*new;

	if (old)
	{
		new = (char*)ft_memalloc(++size);
		if (!new)
			return (NULL);
		i = 0;
		while (old[i] && i < size - 1)
		{
			new[i] = old[i];
			i++;
		}
		while (i++ < size)
			new[i - 1] = '\0';
		free(old);
		return (new);
	}
	return (NULL);
}
