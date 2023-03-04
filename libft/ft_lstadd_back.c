/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:13:06 by msumset           #+#    #+#             */
/*   Updated: 2022/07/27 14:13:11 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*liste;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	liste = *lst;
	liste = ft_lstlast(liste);
	liste->next = new;
}
