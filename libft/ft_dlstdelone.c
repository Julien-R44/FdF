/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 05:04:02 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 12:59:10 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		default_deleter(void *data, size_t size)
{
	(void)size;
	ft_memdel(&data);
}

void			ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*first_link;
	t_dlist		*last_link;

	first_link = (*alst)->before;
	last_link = (*alst)->next;
	if (del == NULL)
		del = default_deleter;
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
	if (last_link && !first_link)
		*alst = last_link;
	else if (first_link && !last_link)
		*alst = first_link;
	else if (first_link && last_link)
	{
		*alst = first_link;
		first_link->next = last_link;
		last_link->before = first_link;
	}
}
