/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:35:00 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:33:03 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	size_t		ft_tabsize(char const *s, char c)
{
	unsigned int	i;
	size_t			counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static	char		**ft_tabfill(char **tab, char const *s, char c)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	size = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				tab[j] = ft_strnew((size_t)size);
				if (tab[j] == NULL)
					return (NULL);
				ft_strncpy(tab[j], &s[i - size + 1], size);
				size = 0;
				j++;
			}
		}
		i++;
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s != 0)
	{
		tab = (char**)ft_memalloc(sizeof(char*) * (ft_tabsize(s, c) + 1));
		if (tab == NULL)
			return (NULL);
		return (ft_tabfill(tab, s, c));
	}
	return (0);
}
