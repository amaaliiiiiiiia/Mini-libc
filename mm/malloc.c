// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (p == MAP_FAILED) {
		return NULL;
	}
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p = malloc(nmemb * size);
	if (p == NULL) {
		return NULL;
	}
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
    struct mem_list *p = mem_list_find(ptr);
	p = p->start;
    if (p->next != NULL) {
        mem_list_del(p);
		p = p->next;
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	ptr = malloc(size);

	if (ptr == NULL) {
		return NULL;
	}

	return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	ptr = malloc(nmemb * size);

	if (ptr == NULL) {
		return NULL;
	}

	return ptr;
}
