/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 08:44:29 by wfung             #+#    #+#             */
/*   Updated: 2017/05/05 14:57:24 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		print_store(t_store *store)
{
	int		i;

	i = 0;
	while (store->next)
	{
		printf("//store [%i] [%i]\n", i, store->x);
		store = store->next;
	//	printf("/store [%i] [%i]\n", i, store->x);
	}
}

t_store		*ft_db(int row, int col)
{
	int			i;
	int			total;
	t_store		*store;
	t_store		*head;

	i = 0;
	total = row * col + 1;
	if (!(store = (t_store*)malloc(sizeof(t_store) * (1))))
		return (NULL);
	store->next = NULL;
	head = store;
	while (i < total)
	{
		if (!(store->next = (t_store*)malloc(sizeof(t_store) * (1))))
			return (NULL);
		store->x = i;
		printf("store->x i %i [%i]\n", i, store->x);
	//	printf("db i = [%i]\n", i);
		i++;
		store = store->next;
	}
	store->next = NULL;
	return (head);
}

int		main(void)
{
	int		x = 5;
	int		y = 5;
	t_store	*hey;
	hey = ft_db(x, y);
	print_store(hey);
	return (0);
}