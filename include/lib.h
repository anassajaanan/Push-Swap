/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:34:14 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/18 10:34:17 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_LIB_H
#define PUSH_LIB_H

# include <stdlib.h>

char	    **ft_split(const char *str, char sep);
long int	ft_atoi(const char *str);
int	        is_numeric(const char *str);
int         ft_strcmp(char *s1, char *s2);
char	    *ft_strdup(const char *s);
size_t	    ft_strlcpy(char *dest, const char *src, size_t size);
size_t	    ft_strlen(const char *str);

#endif //PUSH_LIB_H
