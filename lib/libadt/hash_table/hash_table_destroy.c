/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:16:53 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 22:08:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash_table.h"

static void	hash_table_delete_entry(\
	t_hash_table *hash_table, t_hash_content *target, int bucket)
{
	printf("gonna delete soon... %s\n", target->key);
	if (!target->prev)
		hash_table->bucket_arr[bucket] = target->next;
	else
		target->prev->next = target->next;
	if (target->next)
		target->next->prev = target->prev;
	free(target->key);
	free(target->content);
	free(target);
	hash_table->entry_cnt--;
	printf("just deleted... %s\n", target->key);
}

/**
 * @brief
 * First search for the matching entry from hash table.
 * If delete method finds the matching entry, it deletes the content 
 * from the hash table. Otherwise, nothing happens.
 * Make sure that both hash table and key must not be NULL.
*/
void	hash_table_delete(t_hash_table *hash_table, char *key)
{
	t_hash_content	*target;
	int				bucket;

	if (hash_table->entry_cnt > INITIAL_BUCKET_CNT && \
		hash_table->entry_cnt <= hash_table->bucket_cnt / (LOAD_FACTOR * 2))
	{
		hash_table_shrink(hash_table);
	}
	printf("want to delete %s\n", key);	
	bucket = hash_bucket(key, hash_table->bucket_cnt);
	target = hash_table_search(hash_table, key, bucket);
	if (!target)
		return ;
	hash_table_delete_entry(hash_table, target, bucket);
}

/**
 * @brief
 * Delete every entry of the hash table.
 * Also free the bucket array of the hash table and the hash table itself.
*/
void	hash_table_destroy(t_hash_table *hash_table)
{
	int				i;
	t_hash_content	*next;
	t_hash_content	*target;
	
	i = -1;
	while (++i < hash_table->bucket_cnt)
	{
		target = hash_table->bucket_arr[i];
		while (target)
		{
			next = target->next;
			hash_table_delete_entry(hash_table, target, i);
			target = next;
		}
	}
	free(hash_table->bucket_arr);
	free(hash_table);
}
