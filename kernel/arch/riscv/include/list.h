#ifndef __LIST_H__
#define __LIST_H__

#include <stddef.h>

/**
 * @brief 获取包含指定成员的结构体指针
 * @param ptr 成员指针
 * @param type 结构体类型
 * @param member 成员名
 * @return 结构体指针
 */
#define container_of(ptr, type, member)                            \
	({                                                         \
		const typeof(((type *)0)->member) *__mptr = (ptr); \
		(type *)((char *)__mptr - offsetof(type, member)); \
	})

/**
 * @brief 获取链表条目对应的结构体指针
 * @param ptr 链表头指针
 * @param type 结构体类型
 * @param member 链表头成员名
 * @return 结构体指针
 */
#define list_entry(ptr, type, member) container_of(ptr, type, member)

/**
 * @brief 双向链表头结构体
 */
struct list_head {
	struct list_head *next; /**< 下一个节点 */
	struct list_head *prev; /**< 上一个节点 */
};

/**
 * @brief 初始化链表头
 * @param name 链表头名
 */
#define LIST_HEAD_INIT(name) { &(name), &(name) }

/**
 * @brief 声明并初始化链表头
 * @param name 链表头名
 */
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

/**
 * @brief 初始化链表头
 * @param list 链表头指针
 */
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/**
 * @brief 在链表头后插入新节点
 * @param new 新节点
 * @param head 链表头
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
	/* Lab2 Task1 */
}

/**
 * @brief 在链表尾插入新节点
 * @param new 新节点
 * @param head 链表头
 */
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	/* Lab2 Task1 */
}

/**
 * @brief 从链表中删除节点
 * @param entry 要删除的节点
 */
static inline void list_del(struct list_head *entry)
{
	/* Lab2 Task1 */
}

/**
 * @brief 检查链表是否为空
 * @param head 链表头
 * @return 1 如果为空，0 否则
 */
static inline int list_empty(const struct list_head *head)
{
	/* Lab2 Task1 */
}

/**
 * @brief 遍历链表
 * @param pos 循环变量
 * @param head 链表头
 */
#define list_for_each(pos, head) for (pos;;) /* Lab2 Task1 */

/**
 * @brief 安全遍历链表（允许删除）
 * @param pos 循环变量
 * @param n 临时变量
 * @param head 链表头
 */
#define list_for_each_safe(pos, n, head)                       \
	for (pos = (head)->next, n = pos->next; pos != (head); \
	     pos = n, n = pos->next)

#endif
