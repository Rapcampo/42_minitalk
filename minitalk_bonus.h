/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:37:39 by rapcampo          #+#    #+#             */
/*   Updated: 2024/01/20 18:55:36 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

//libraries
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

//functions utils

unsigned char	*ft_unstrjoin(unsigned char *to_print, unsigned char c);
int				ft_unstrlen(unsigned char *str);

#endif 
