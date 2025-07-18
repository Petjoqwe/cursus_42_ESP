#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* Stack operations */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* Stack utilities */
t_stack	*ft_lstnew_stack(int value);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
void	ft_lstadd_front_stack(t_stack **lst, t_stack *new);
int		ft_lstsize_stack(t_stack *lst);
t_stack	*ft_lstlast_stack(t_stack *lst);
void	ft_lstclear_stack(t_stack **lst);

/* Input validation */
int		is_valid_input(char **argv);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

/* Stack creation */
t_stack	*create_stack(char **argv);
void	assign_index(t_stack *stack_a, int stack_size);

/* Sorting algorithms */
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/* Utilities */
int		get_max_bits(t_stack *stack);
int		get_min_pos(t_stack *stack);
void	free_split(char **split);
long	ft_atol(const char *str);

/* Error handling */
void	error_exit(void);

#endif