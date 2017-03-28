#include "mem_dispatcher.h"

void init(mem_dispatcher *md)
{
	mem_chunk *pointer = NULL;

	md->last_id_used = 0;
	pointer = (mem_chunk*)malloc(sizeof(mem_chunk));
	pointer->id = 0;
	pointer->status = FREE;
	pointer->next = NULL;
	pointer->size = HEAP_SIZE;
	md->first = pointer;
}

void show_memory_map(mem_dispatcher *md)
{
	mem_chunk *start = md->first;
	while(start)
	{
		printf("block id: %d\n\t\tsize: ", start->id);
		printf("%d \tstatus: ", start->size);

		if (start->status == FREE) 
			printf("free\n");
		else 
			printf("allocated\n");

		start = start->next;
	}
}

int allocate(mem_dispatcher *md, int size)
{
	int min = HEAP_SIZE + 1;
	mem_chunk *pointer = NULL, *new_point = NULL, *p_t = NULL;

	pointer = md->first;
	while (pointer)
	{
		if (pointer->size >= size && pointer->size < min && pointer->status == FREE) 
		{
			min = pointer->size;
			p_t = pointer;
		}
		pointer = pointer->next;
	}

	if (!p_t) 
		return -1;
	if (size == p_t->size)
	{
		p_t->status = ALLOCATED;
		return p_t->id;
	}
	
	new_point = (mem_chunk*)malloc(sizeof(mem_chunk));
	new_point->next = p_t->next;

	new_point->status = ALLOCATED;

	p_t->size = p_t->size - size;
	new_point->size = size;

	md->last_id_used++;
	new_point->id = md->last_id_used;
	
	p_t->next = new_point;

	return md->last_id_used;
}

int deallocate(mem_dispatcher *md, int block_id)
{ 
	mem_chunk *pointer, *p; 

	pointer = md->first; 
	while (pointer && pointer->id != block_id) 
		pointer = pointer->next; 

	if (NULL == pointer) 
		return -1; 

	pointer->status = FREE; 
	pointer = md->first; 
	do
	{ 
		if (pointer->next && !pointer->status) 
			if (!pointer->next->status)
			{ 
				p = pointer->next; 
				pointer->size = pointer->size + p->size; 
				pointer->next = p->next; 
				free(p); 
			} 
			else 
				pointer = pointer->next; 
		else 
			pointer = pointer->next; 
	} while (pointer->next);

	return 0; 
}

void defragment(mem_dispatcher *md)
{
	mem_chunk *pointer, *p = NULL, *p_t = NULL;

	pointer = md->first;
	while (pointer->status != FREE && pointer != NULL)
		pointer = pointer->next;
	
	p_t = pointer;
	while (p_t->next != NULL)
	{
		if (p_t->next->status == FREE)
		{
			p = p_t->next;
			pointer->size = pointer->size + p->size;
			p_t->next = p->next;
			free(p);
		}
		else p_t = p_t->next;
	}
}

