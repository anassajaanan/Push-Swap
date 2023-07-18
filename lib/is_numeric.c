/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:27:14 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/18 07:27:16 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	is_numeric(const char *str)
{
	if (*str && (*str == '-' || *str == '+'))
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}
