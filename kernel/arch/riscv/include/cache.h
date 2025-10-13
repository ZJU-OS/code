#ifndef __CACHE_H__
#define __CACHE_H__

#include <list.h>
#include <stddef.h>

/**
 * @struct kmem_cache
 * @brief 内存缓存结构体，用于管理内核对象的缓存分配。
 *
 * 该结构体用于实现内核对象的缓存机制，提升对象分配与释放的效率。
 */
struct kmem_cache {
	struct list_head list; /** 缓存链表节点，用于将多个缓存结构体连接起来。 */
	const char *name; /** 缓存名称，用于标识不同类型的缓存。 */
	size_t obj_size; /** 每个缓存对象的大小（字节）。 */
	struct list_head
		free_objects; /** 空闲对象链表，管理当前未分配的缓存对象。 */
};

/**
 * @brief 创建一个新的内存缓存对象
 * 
 * 此函数用于创建一个指定名称和大小的内存缓存（kmem_cache），
 * 以便高效地分配和释放固定大小的内存块。
 * 
 * @param name 缓存的名称，用于标识该缓存
 * @param size 每个缓存对象的大小（字节）
 * @return 返回新创建的 kmem_cache 指针，失败时返回 NULL
 */
struct kmem_cache *kmem_cache_create(const char *name, size_t size);

/**
 * @brief 从指定的内存缓存中分配一个对象
 * 
 * 此函数从给定的 kmem_cache 中分配一个对象，如果没有空闲对象则扩展缓存。
 * 
 * @param cachep 指向要从中分配对象的 kmem_cache 的指针
 * @return 返回分配的对象指针，失败时返回 NULL
 */
void *kmem_cache_alloc(struct kmem_cache *cachep);

/**
 * @brief 释放一个对象回指定的内存缓存
 * 
 * 此函数将一个对象释放回给定的 kmem_cache 中，以便后续分配时重用。
 * 
 * @param cachep 指向要释放对象到的 kmem_cache 的指针
 * @param objp 要释放的对象指针
 */
void kmem_cache_free(struct kmem_cache *cachep, void *objp);

#endif