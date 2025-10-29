/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:51:07 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 20:24:55 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = (*lst).next;
	}
	return (cnt);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	(*new).next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*first;
	int		i;

	if (!new)
		ft_error(*lst);
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	first = *lst;
	i = 0;
	while ((**lst).next)
		*lst = (**lst).next;
	(**lst).next = new;
	*lst = first;
}

t_node	*ft_lstnew(int n)
{
	t_node	*ll;

	ll = (t_node *) malloc(sizeof(t_node));
	if (!ll)
		return (NULL);
	(*ll).n = n;
	(*ll).next = NULL;
	return (ll);
}

void	stack_free(t_node *lst)
{
	t_node	*temp;

	while (lst)
	{
		temp = (*lst).next;
		free(lst);
		lst = temp;
	}
}
