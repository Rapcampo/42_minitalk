/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:37:39 by rapcampo          #+#    #+#             */
/*   Updated: 2023/11/23 13:37:54 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//libraries
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"

//functions utils

unsigned char	*ft_unstrjoin(unsigned char const *to_print, unsigned char c);
int	ft_unstrlen(unsigned char const *str);

#endif 
