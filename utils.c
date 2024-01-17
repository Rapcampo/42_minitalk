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

int	ft_unstrlen(unsigned char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned char	*ft_unstrjoin(unsigned char *to_print, unsigned char c)
{
	unsigned char	*str;

	auto size_t i = 0;
	auto size_t j = 0;
	auto size_t size = 0;
	if (to_print)
		size = ft_unstrlen(to_print);
	//size++;
	str = malloc(sizeof(unsigned char *) * size + 2);
	if (str == NULL)
		return (NULL);
	if (to_print)
	{
		while (to_print[i])
			str[j++] = to_print[i++];
	}
	str[j] = c;
	j++;
	str[j] = '\0';
	free(to_print);
	return (str);
}
