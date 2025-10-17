#include <csr.h>
#include <cache.h>
#include <mm.h>
#include <string.h>
#include <private_kdefs.h>
#include <log.h>
#include <printk.h>

static LIST_HEAD(free_caches);
static LIST_HEAD(used_caches);

struct kmem_cache *kmem_cache_create(const char *name, size_t size)
{
	interrupt_disable();
	struct list_head *pos;

	list_for_each(pos, &used_caches)
	{
		struct kmem_cache *cache =
			list_entry(pos, struct kmem_cache, list);
		if (cache->name && strcmp(cache->name, name) == 0) {
			interrupt_enable();
			return cache;
		}
	}

	if (list_empty(&free_caches)) {
		void *cache_pool = alloc_page();

		size_t num_caches = PGSIZE / sizeof(struct kmem_cache);
		struct kmem_cache *new_cache = (struct kmem_cache *)cache_pool;

		for (size_t i = 0; i < num_caches; i++) {
			new_cache[i].name = NULL;
			list_add_tail(&new_cache[i].list, &free_caches);
		}
	}

	struct kmem_cache *cache =
		list_entry(free_caches.next, struct kmem_cache, list);
	list_del(&cache->list);

	cache->name = name;
	cache->obj_size = size;
	INIT_LIST_HEAD(&cache->free_objects);

	list_add_tail(&cache->list, &used_caches);
	interrupt_enable();

	return cache;
}

void *kmem_cache_alloc(struct kmem_cache *cachep)
{
	interrupt_disable();
	if (list_empty(&cachep->free_objects)) {
		void *page = alloc_page();

		size_t obj_total_size =
			sizeof(struct list_head) + cachep->obj_size;
		size_t num_objs = PGSIZE / obj_total_size;

		for (size_t i = 0; i < num_objs; i++) {
			struct list_head *link =
				(struct list_head *)(page + i * obj_total_size);
			list_add_tail(link, &cachep->free_objects);
		}
	}

	struct list_head *obj_link = cachep->free_objects.next;
	list_del(obj_link);

	void *obj = (void *)obj_link + sizeof(struct list_head);
	interrupt_enable();
	return obj;
}

void kmem_cache_free(struct kmem_cache *cachep, void *objp)
{
	interrupt_disable();
	memset(objp, 0, cachep->obj_size);
	struct list_head *link =
		(struct list_head *)(objp - sizeof(struct list_head));
	list_add(link, &cachep->free_objects);
	interrupt_enable();
}
