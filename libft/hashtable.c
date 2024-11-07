/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:30:51 by sejjeong          #+#    #+#             */
/*   Updated: 2024/08/29 16:10:52 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

const char	*get_value_or_null(const t_hashtable *table, const int key)
{
	t_table_node	*temp;
	int				hash;

	hash = key % TABLE_SIZE;
	temp = table->node[hash];
	while (temp != NULL && temp->key != key)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return (NULL);
	}
	return ((const char *)(temp->value));
}

bool	update_key(t_hashtable *table, const int key, const char *pa_change)
{
	int				hash;
	t_table_node	*temp;

	hash = key % TABLE_SIZE;
	temp = table->node[hash];
	while (temp != NULL)
	{
		if (temp->key == key)
		{
			free((char *)(temp->value));
			temp->value = pa_change;
			return (true);
		}
		temp = temp->next;
	}
	if (add_last_node_malloc(table, key, pa_change) == false)
	{
		return (false);
	}
	return (true);
}

bool	remove_key(t_hashtable *table, const int key)
{
	t_table_node	*p;
	t_table_node	*prev;
	int				hash;

	hash = key % TABLE_SIZE;
	p = table->node[hash];
	prev = NULL;
	while (p != NULL)
	{
		if (p->key == key)
		{
			free((char *)(p->value));
			if (prev == NULL)
				table->node[hash] = p->next;
			else
				prev->next = p->next;
			free(p);
			return (true);
		}
		prev = p;
		p = p->next;
	}
	return (false);
}

bool	add_last_node_malloc(t_hashtable *table, \
const int key, const char *pa_value)
{
	t_table_node	*temp;
	t_table_node	*new;
	int				hash;

	new = malloc(sizeof(t_table_node));
	if (new == NULL)
	{
		return (false);
	}
	new->key = key;
	new->value = pa_value;
	new->next = NULL;
	hash = key % TABLE_SIZE;
	temp = table->node[hash];
	if (temp == NULL)
	{
		table->node[hash] = new;
		return (true);
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	return (true);
}
