#include "minishell.h"

t_token	*ft_double_lstnew(char *content,int type)
{
	t_token	*new_stack;

	new_stack = malloc(sizeof(t_token));
	if (!new_stack)
		return (NULL);
	new_stack->prev = NULL;
	new_stack->content = ft_strdup(content);
	new_stack->type = type;
	new_stack->next = NULL;
	return (new_stack);
}