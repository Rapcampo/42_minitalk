/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:34 by rapcampo          #+#    #+#             */
/*   Updated: 2024/01/15 12:06:39 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_unstrlen(unsigned char const *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned char	*ft_unstrjoin(unsigned char const *to_print, unsigned char c)
{
	size_t		i;
	size_t		j;
	unsigned char	*str;
	size_t		size;

	i = 0;
	j = 0;
	size = 0;
	if (to_print)
		size = ft_unstrlen(to_print) + 1;
	str = malloc(sizeof(unsigned char *) * size + 1);
	if (str == NULL)
		return (NULL);
	while (str[j])
		j++;
	if (to_print)	
	{
		while (to_print[i])
			str[j++] = to_print[i++];
	}
	str[j] = c;
	j++;
	str[j] = '\0';
	return (str);
}
