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
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

struct	s_queue_node
{
	char				val;
	struct s_queue_node	*next;
};

typedef struct s_queue
{
	struct s_queue_node	*front;
	struct s_queue_node	*rear;
}						t_queue;

/* QUEUE */
void	init_queue(t_queue *q);
void	enqueue(t_queue *q, char c);
char	dequeue(t_queue *q);
int		queue_is_empty(t_queue *q);

/* GET_NEXT_LINE */
int		contains_newline(t_queue *q);
char	*get_line(t_queue *q);
char	*get_last_line(t_queue *q);
char	*handle_bytes(ssize_t bytes, t_queue *q, char *buffer, int *fd);
char	*get_next_line(int fd);

/* LIBFT */
char	    **ft_split(const char *str, char sep);
long int	ft_atoi(const char *str);
int	        is_numeric(const char *str);
int         ft_strcmp(char *s1, char *s2);
char	    *ft_strdup(const char *s);
size_t	    ft_strlcpy(char *dest, const char *src, size_t size);
size_t	    ft_strlen(const char *str);
void	    ft_putstr(char *s);

#endif //PUSH_LIB_H
