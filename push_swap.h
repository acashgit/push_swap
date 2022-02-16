/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:14:21 by acash             #+#    #+#             */
/*   Updated: 2021/12/23 22:15:07 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

typedef struct s_mylist
{
	struct s_mylist	*next;
	struct s_mylist	*prev;
	int				value;
	int				del;
	int				order;
	int				asycele;
	int				bsycele;
}	t_mylist;

void		ft_putchar(char c);
int			ft_atoi(char *str);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_checkargs(size_t count, int *a);
int			*ft_fill(int count, int *stack_a, char **str, int code);
void		ft_easysort(int count, t_mylist **stack_a, t_mylist **stack_b);
void		ft_error(void);
size_t		ft_strlen(char *s);
t_mylist	*ft_create_elem(int value, int order, int del);
t_mylist	*ft_filllist(int count, int *a);
void		ft_list_clear(t_mylist **list);
int			ft_sa(t_mylist **stack_a, int code);
int			ft_sb(t_mylist **stack_b, int code);
int			ft_ss(t_mylist **stack_a, t_mylist **stack_b, int code);
int			ft_pa(t_mylist **stack_a, t_mylist **stack_b);
int			ft_pb(t_mylist **stack_a, t_mylist **stack_b);
int			ft_ra(t_mylist **stack_a, int code);
int			ft_rb(t_mylist **stack_b, int code);
int			ft_rr(t_mylist **stack_a, t_mylist **stack_b, int code);
int			ft_rra(t_mylist **stack_a, int code);
int			ft_rrb(t_mylist **stack_b, int code);
int			ft_rrr(t_mylist **stack_a, t_mylist **stack_b, int code);
void		fc_norm_help(t_mylist **a, t_mylist **b, int code);
void		ft_hardsort(int count, t_mylist **a, t_mylist **b, int *arr);
size_t		ft_strlen(char *s);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);
void		ft_sortth(t_mylist **a);
void		ft_scoreb(int count, t_mylist **b, int a_count);
void		ft_scoreuodate(int count, t_mylist **b, t_mylist **a, int a_count);
t_mylist	*ft_lastll(t_mylist *stack_a);
void		ft_move(t_mylist **a, t_mylist **b);
void		ft_help_hs(int count, t_mylist **a, t_mylist **b, int a_count);
void		ft_move_hs(t_mylist *aa, t_mylist **a, t_mylist **b, int *keyw);
void		ft_finder(t_mylist *bb, int *ss, int *code);
void		ft_print(int ra, int rb, int i);
void		ft_print2(int rra, int rrb, int i);
void		ft_printend(int omega, int count);
void		ft_fcnorm(t_mylist **a, t_mylist **b, int *keyw);
int			get_next_line(char **line);
int			ft_read_comm(t_mylist **a, t_mylist **b, char *line);
void		ft_bcheckargs(size_t count, int *a);
void		ft_omegal(char *s);

#endif
